class Solution {
public:
    int numDistinct(string s, string t) {
        const int N = s.length();
        const int M = t.length();
        
        s = "#" + s;
        t = "#" + t;
        
        // dp[i][j]: number of distinct subsequences of s[1 .. i] which equals t[1 .. j]
        vector<vector<long long>> dp(N + 2, vector<long long>(M + 2));
        
        for(int i = 0; i <= N; ++i){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                dp[i][j] += dp[i - 1][j];
                if(s[i] == t[j]){
                    dp[i][j] += dp[i - 1][j - 1];
                }
                // It is guaranteed the answer fits on a 32-bit signed integer => dp[i][j] <= INT_MAX
                dp[i][j] = min(dp[i][j], (long long)INT_MAX);
            }
        }
        
        return dp[N][M];
    }
};