class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MODULO = 1e9 + 7;

        // dp[i][j]: number of possible playlists of length i
        //           containing j unique songs (from a pool of n unique songs)
        vector<vector<int>> dp(goal + 1, vector<int>(n + 1));
        dp[0][0] = 1;

        for(int i = 1; i <= goal; ++i){
            for(int j = 1; j <= min(i, n); ++j){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * 1LL * (n - j + 1)) % MODULO;
                if(j > k){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * 1LL * (j - k)) % MODULO;
                }
            }
        }

        return dp[goal][n];
    }
};