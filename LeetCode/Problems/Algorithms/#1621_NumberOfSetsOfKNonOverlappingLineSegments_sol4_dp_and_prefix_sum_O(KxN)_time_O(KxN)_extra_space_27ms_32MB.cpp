class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MODULO = 1'000'000'007;

        // dp[i][j]: number of ways we can draw exactly i non-overlapping segments
        //           given j points
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));

        dp[1][2] = 1;
        for(int j = 3; j <= n; ++j){
            dp[1][j] = (dp[1][j - 1] + (j - 1)) % MODULO;
        }

        for(int i = 2; i <= k; ++i){
            int prefSumPrevDP = 0;
            for(int j = 2; j <= n; ++j){
                prefSumPrevDP = (prefSumPrevDP + dp[i - 1][j - 1]) % MODULO;
                dp[i][j] = (dp[i][j - 1] + prefSumPrevDP) % MODULO;
            }
        }

        return dp[k][n];
    }
};