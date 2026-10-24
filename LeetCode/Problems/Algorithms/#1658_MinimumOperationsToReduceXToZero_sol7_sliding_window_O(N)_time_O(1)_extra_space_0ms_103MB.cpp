class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int TARGET_SUM = TOTAL_SUM - x;

        int maxWindowSize = -1;
        int currWindowSum = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            currWindowSum += nums[r];
            while(l <= r && currWindowSum > TARGET_SUM){
                currWindowSum -= nums[l];
                l += 1;
            }
            if(currWindowSum == TARGET_SUM){
                maxWindowSize = max(maxWindowSize, r - l + 1);
            }
        }

        if(maxWindowSize >= 0){
            return N - maxWindowSize;
        }

        return -1;
    }
};