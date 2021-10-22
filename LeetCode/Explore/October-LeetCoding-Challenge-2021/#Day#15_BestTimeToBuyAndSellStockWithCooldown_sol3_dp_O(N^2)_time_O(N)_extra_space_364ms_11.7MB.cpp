class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        const int BUY = 0;
        const int SELL = 1;
        
        // dp[i][BUY]: max profit if you buy on the ith day
        // dp[i][SELL]: max profit if you sell on the ith day
        vector<vector<int>> dp(N, vector<int>(2, 0));
        dp[0][BUY] = -prices[0];
        dp[0][SELL] = 0;
        
        int maxProfit = 0;
        for(int i = 1; i < N; ++i){
            dp[i][BUY] = -prices[i];
            for(int j = 0; j <= i - 2; ++j){
                dp[i][BUY] = max(dp[i][BUY], dp[j][SELL] - prices[i]);
            }
            for(int j = 0; j <= i - 1; ++j){
                dp[i][SELL] = max(dp[i][SELL], dp[j][BUY] + prices[i]);
            }
            maxProfit = max(maxProfit, dp[i][SELL]);
        }
        
        return maxProfit;
    }
};