class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MODULO = 1e9 + 7;

        // At ith iteration:
        //    dp[i % 2][j]: number of possible playlists of length i
        //                  containing j unique songs (from a pool of n unique songs)
        vector<vector<int>> dp(2, vector<int>(n + 1));
        dp[0][0] = 1;

        for(int i = 1; i <= goal; ++i){
            fill(dp[i % 2].begin(), dp[i % 2].end(), 0);
            for(int j = 1; j <= min(i, n); ++j){
                dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][j - 1] * 1LL * (n - j + 1)) % MODULO;
                if(j > k){
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][j] * 1LL * (j - k)) % MODULO;
                }
            }
        }

        return dp[goal % 2][n];
    }
};