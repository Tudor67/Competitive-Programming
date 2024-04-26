class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        const int N = prices.size();
        const int INF = 1e9;

        // dp[i]: min cost to take fruits[i .. N - 1]
        vector<int> dp(N + 1, INF);
        dp[N] = 0;
        for(int i = N - 1; i >= 0; --i){
            for(int j = i + 1; j <= min(N, i + i + 2); ++j){
                dp[i] = min(dp[i], prices[i] + dp[j]);
            }
        }
        
        return dp[0];
    }
};