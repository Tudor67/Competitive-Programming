class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        const int BUY = 0;
        const int SELL = 1;
        
        // dp[i][BUY]: max profit if your last transaction on range [0 .. i] is `buy`
        // dp[i][SELL]: max profit if your last transaction on range [0 .. i] is `sell`
        vector<vector<int>> dp(3, vector<int>(2, 0));
        dp[0][BUY] = -prices[0];
        dp[0][SELL] = 0;
        
        for(int i = 1; i < N; ++i){
            dp[i % 3][BUY] = max(dp[(i - 1) % 3][BUY], -prices[i]);
            if(i >= 2){
                dp[i % 3][BUY] = max(dp[i % 3][BUY], dp[(i - 2) % 3][SELL] - prices[i]);
            }
            dp[i % 3][SELL] = max(dp[(i - 1) % 3][SELL], dp[(i - 1) % 3][BUY] + prices[i]);
        }
        
        return dp[(N - 1) % 3][SELL];
    }
};