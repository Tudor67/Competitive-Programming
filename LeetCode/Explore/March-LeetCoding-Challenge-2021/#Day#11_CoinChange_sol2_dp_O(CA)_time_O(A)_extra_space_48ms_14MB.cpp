class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int N = coins.size();
        const int INF = 1e8;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for(int coin: coins){
            for(int j = coin; j <= amount; ++j){
                dp[j] = min(1 + dp[j - coin], dp[j]);
            }
        }
        if(dp[amount] == INF){
            dp[amount] = -1;
        }
        return dp[amount];
    }
};