class Solution {
public:
    int numSquares(int n) {
        const int INF = 1e9;

        // dp[i]: the least number of perfect squares that sum to n
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};