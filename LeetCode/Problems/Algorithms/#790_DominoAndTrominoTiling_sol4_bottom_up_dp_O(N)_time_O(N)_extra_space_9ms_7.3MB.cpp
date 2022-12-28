class Solution {
public:
    int numTilings(int N) {
        // Configs:
        // Config 0  Config 1  Config 2
        //   10        11        11
        //   11        10        11

        // dp[i][c]: number of ways to tile an 2 x i board
        //           when the last config is c
        const int MODULO = 1e9 + 7;
        vector<vector<int>> dp(N + 3, vector<int>(3));
        dp[1][2] = 1;
        dp[2][0] = 1;
        dp[2][1] = 1;
        dp[2][2] = 2;
        for(int i = 3; i <= N; ++i){
            dp[i][0] = (dp[i - 2][2] + dp[i - 1][1]) % MODULO;
            dp[i][1] = (dp[i - 2][2] + dp[i - 1][0]) % MODULO;
            dp[i][2] = ((dp[i - 1][0] + dp[i - 1][1]) % MODULO +
                        (dp[i - 1][2] + dp[i - 2][2]) % MODULO) % MODULO;
        }

        return dp[N][2];
    }
};