class Solution {
public:
    int numberOfSets(int N, int K) {
        const int MODULO = 1e9 + 7;

        // At ith iteration:
        //    dp[i % 2][j]: number of ways to draw i non-overlapping line segments
        //                  that cover points [0 .. j]
        vector<vector<long long>> dp(2, vector<long long>(N));
        for(int j = 0; j < N; ++j){
            dp[0][j] = 1;
        }

        for(int i = 1; i <= K; ++i){
            for(int j = 0; j < N; ++j){
                dp[i % 2][j] = 0;
            }
            long long prefSum = dp[(i - 1) % 2][0]; // prefSum = dp[(i - 1) % 2][0] + dp[(i - 1) % 2][1] + ... + dp[(i - 1) % 2][j - 1]
            for(int j = 1; j < N; ++j){
                dp[i % 2][j] += dp[i % 2][j - 1];
                dp[i % 2][j] += prefSum;
                dp[i % 2][j] %= MODULO;
                prefSum += dp[(i - 1) % 2][j];
                prefSum %= MODULO;
            }
        }

        return dp[K % 2][N - 1];
    }
};