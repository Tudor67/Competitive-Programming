class Solution {
public:
    int numberOfSets(int N, int K) {
        const int MODULO = 1e9 + 7;

        // dp[i][j]: number of ways to draw i non-overlapping line segments
        //           that cover points [0 .. j]
        vector<vector<long long>> dp(K + 1, vector<long long>(N));
        for(int j = 0; j < N; ++j){
            dp[0][j] = 1;
        }

        for(int i = 1; i <= K; ++i){
            long long prefSum = dp[i - 1][0]; // prefSum = dp[i - 1][0] + dp[i - 1][1] + ... + dp[i - 1][j - 1]
            for(int j = 1; j < N; ++j){
                dp[i][j] += dp[i][j - 1];
                dp[i][j] += prefSum;
                dp[i][j] %= MODULO;
                prefSum += dp[i - 1][j];
                prefSum %= MODULO;
            }
        }

        return dp[K][N - 1];
    }
};