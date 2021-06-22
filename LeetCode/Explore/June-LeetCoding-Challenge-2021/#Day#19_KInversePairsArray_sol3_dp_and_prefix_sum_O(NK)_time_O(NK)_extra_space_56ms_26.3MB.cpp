class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MODULO = 1e9 + 7;
        
        // dp[n][k]: number (% MODULO) of arrays of length n with exactly k inverse pairs
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        
        // prefSum[i][j] = (dp[i][0] + dp[i][1] + ... + dp[i][j]) % MODULO;
        vector<vector<int>> prefSum(n + 1, vector<int>(k + 1));
        
        for(int i = 1; i <= n; ++i){
            dp[i][0] = 1;
            prefSum[i][0] = 1;
            for(int j = 1; j <= k; ++j){
                dp[i][j] = (prefSum[i - 1][j] - (j - i >= 0 ? prefSum[i - 1][j - i] : 0) + MODULO) % MODULO;
                prefSum[i][j] = (prefSum[i][j - 1] + dp[i][j]) % MODULO;
            }
        }
        
        return dp[n][k];
    }
};