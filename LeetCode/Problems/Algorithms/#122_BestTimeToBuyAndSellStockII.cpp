class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        
        if(n > 0){
            vector<vector<int>> dp(2, vector<int>(n, 0));
            // dp[0][j] - max profit on the jth day when the last operation is "buy"
            // dp[1][j] - max profit on the jth day when the last operation is "sell"
            dp[0][0] = -prices[0];
            dp[1][0] = 0;
            for(int j = 1; j < n; ++j){
                dp[0][j] = max(dp[0][j - 1], dp[1][j - 1] - prices[j]);
                dp[1][j] = max(dp[1][j - 1], dp[0][j - 1] + prices[j]);
            }
            ans = dp[1][n - 1];
        }
        
        return ans;
    }
};