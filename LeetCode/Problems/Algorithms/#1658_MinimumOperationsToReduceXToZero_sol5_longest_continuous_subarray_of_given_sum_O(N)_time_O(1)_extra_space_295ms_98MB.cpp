class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int TARGET_SUM = TOTAL_SUM - x;
        
        // finding the shortest prefix + suffix with sum equal to x
        // is equivalent to
        // finding the longest subarray with sum equal to TARGET_SUM = TOTAL_SUM - x
        
        if(TARGET_SUM < 0){
            return -1;
        }
        
        if(TARGET_SUM == 0){
            return N;
        }
        
        int sum = 0;    // sum of nums[i .. j]
        int i = 0;
        int maxLen = 0; // length of the longest subarray with sum equal to TARGET_SUM
        for(int j = 0; j < N; ++j){
            sum += nums[j];
            while(sum > TARGET_SUM){
                sum -= nums[i];
                i += 1;
            }
            // longest subarray nums[i .. j] ending at index j
            // such that sum(nums[i .. j]) <= TARGET_SUM
            if(sum == TARGET_SUM){
                maxLen = max(maxLen, j - i + 1);
            }
        }
        
        int minOps = -1;
        if(maxLen >= 1){
            minOps = N - maxLen;
        }
        
        return minOps;
    }
};