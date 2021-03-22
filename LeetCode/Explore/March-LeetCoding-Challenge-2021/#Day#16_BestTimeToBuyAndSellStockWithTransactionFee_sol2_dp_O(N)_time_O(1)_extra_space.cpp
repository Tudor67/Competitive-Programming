class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int N = prices.size();
        
        vector<int> dp(2, 0);
        int maxDiff = -prices[0];
        for(int i = 1; i < N; ++i){
            dp[i % 2] = max(prices[i] - fee + maxDiff, dp[(i - 1) % 2]);
            maxDiff = max(dp[(i - 1) % 2] - prices[i], maxDiff);
        }
        
        return dp[(N - 1) % 2];
    }
};