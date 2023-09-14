class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int N = nums.size();

        // dp[s]: number of possible sequences that add up to s
        vector<long long> dp(target + 1);
        dp[0] = 1;
        for(int s = 1; s <= target; ++s){
            for(int num: nums){
                if(num <= s){
                    dp[s] += dp[s - num];
                    dp[s] = min(dp[s], (long long)INT_MAX);
                }
            }
        }

        return dp[target];
    }
};