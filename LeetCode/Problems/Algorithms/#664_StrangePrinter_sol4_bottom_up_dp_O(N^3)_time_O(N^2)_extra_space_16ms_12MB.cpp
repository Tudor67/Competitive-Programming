class Solution {
public:
    int strangePrinter(string s) {
        const int N = s.length();

        vector<vector<int>> dp(N + 1, vector<int>(N));
        for(int i = N - 1; i >= 0; --i){
            for(int j = i; j < N; ++j){
                dp[i][j] = 1 + dp[i + 1][j];
                for(int k = i + 1; k <= j; ++k){
                    if(s[i] == s[k]){
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
                    }
                }
            }
        }

        return dp[0][N - 1];
    }
};