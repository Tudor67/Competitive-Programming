class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[target]: number of possible combinations that add up to target
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int currentTarget = 1; currentTarget <= target; ++currentTarget){
            for(int num: nums){
                if(num <= currentTarget && dp[currentTarget] <= INT_MAX - dp[currentTarget - num]){
                    dp[currentTarget] += dp[currentTarget - num];
                }
            }
        }
        return dp[target];
    }
};