class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;

        for(int coin: coins){
            for(int sum = coin; sum <= amount; ++sum){
                if(dp[sum] <= INT_MAX - dp[sum - coin]){
                    dp[sum] += dp[sum - coin];
                }
            }
        }

        return dp[amount];
    }
};