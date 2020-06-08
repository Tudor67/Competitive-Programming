class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int coin: coins){
            for(int j = coin; j <= amount; ++j){
                dp[j] += dp[j - coin];
            }
        }
        
        if(coins.empty() || amount == 0){
            dp[0] = 1;
        }else{
            dp[0] = 0;
        }
        
        return dp[amount];
    }
};