class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0LL);
        
        // Step 1: special case (N == 1)
        if(N == 1){
            return 0;
        }
        
        // Step 2: check diffs for i in range [0 .. N - 2]        
        long long prefSum = nums[0];
        long long suffSum = TOTAL_SUM - nums[0];
        long long minDiff = abs(prefSum / 1 - suffSum / (N - 1));
        int minDiffIdx = 0;
        for(int i = 1; i + 1 < N; ++i){
            prefSum += nums[i];
            suffSum -= nums[i];
            long long leftAvg = prefSum / (i + 1);
            long long rightAvg = suffSum / (N - 1 - i);
            long long diff = abs(leftAvg - rightAvg);
            if(diff < minDiff){
                minDiff = diff;
                minDiffIdx = i;
            }
        }
        
        // Step 3: check diff for i = N - 1
        long long diff = abs(TOTAL_SUM / N);
        if(diff < minDiff){
            minDiff = diff;
            minDiffIdx = N - 1;
        }
        
        return minDiffIdx;
    }
};