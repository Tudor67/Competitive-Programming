class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int N = min(steps / 2 + 1, arrLen);
        const int K = steps;
        const int MODULO = 1e9 + 7;

        // At Kth iteration:
        //    dp[K % 2][i]: number of ways such that your pointer is at index i
        //                  after K steps (and starting at index 1, not 0)
        vector<vector<int>> dp(2, vector<int>(N + 2));
        dp[0][1] = 1;
        for(int step = 1; step <= K; ++step){
            for(int i = 1; i <= N; ++i){
                dp[step % 2][i] = dp[(step - 1) % 2][i];
                dp[step % 2][i] = (dp[step % 2][i] + dp[(step - 1) % 2][i - 1]) % MODULO;
                dp[step % 2][i] = (dp[step % 2][i] + dp[(step - 1) % 2][i + 1]) % MODULO;
            }
        }

        return dp[K % 2][1];
    }
};