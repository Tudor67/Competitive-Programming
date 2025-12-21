class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const int N = prices.size();

        // dp[t][i]: max profit from prices[0 .. i] when using at most t transactions
        vector<vector<long long>> dp(k + 1, vector<long long>(N));

        for(int t = 1; t <= k; ++t){
            long long maxDiff = -prices[0];
            long long maxSum = prices[0];
            for(int i = 1; i < N; ++i){
                dp[t][i] = max({dp[t][i - 1], maxDiff + prices[i], maxSum - prices[i]});
                maxDiff = max(maxDiff, dp[t - 1][i - 1] - prices[i]);
                maxSum = max(maxSum, dp[t - 1][i - 1] + prices[i]);
            }
        }

        return dp[k][N - 1];
    }
};