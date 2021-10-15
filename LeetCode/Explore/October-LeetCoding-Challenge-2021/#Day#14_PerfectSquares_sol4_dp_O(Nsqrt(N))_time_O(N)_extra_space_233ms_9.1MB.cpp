class Solution {
public:
    int numSquares(int N) {
        // dp[i]: least number of perfect square numbers that sum to i
        vector<int> dp(N + 1, N + 1);
        dp[0] = 0;
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[N];
    }
};