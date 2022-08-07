class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[target]: number of possible combinations that add up to target
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int sum = 1; sum <= target; ++sum){
            for(int num: nums){
                if(sum - num >= 0 && dp[sum] <= INT_MAX - dp[sum - num]){
                    dp[sum] += dp[sum - num];
                }
            }
        }
        return dp[target];
    }
};