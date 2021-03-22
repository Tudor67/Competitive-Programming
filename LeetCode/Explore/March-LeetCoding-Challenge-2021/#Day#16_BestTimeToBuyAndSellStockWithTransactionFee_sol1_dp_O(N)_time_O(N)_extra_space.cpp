class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int N = prices.size();
        
        vector<int> dp(N, 0);
        int maxDiff = -prices[0];
        for(int i = 1; i < N; ++i){
            dp[i] = max(prices[i] - fee + maxDiff, dp[i - 1]);
            maxDiff = max(dp[i - 1] - prices[i], maxDiff);
        }
        
        return dp[N - 1];
    }
};