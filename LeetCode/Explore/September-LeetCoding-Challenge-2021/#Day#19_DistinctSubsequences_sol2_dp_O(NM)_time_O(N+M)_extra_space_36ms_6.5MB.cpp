class Solution {
public:
    int numDistinct(string s, string t) {
        const int N = s.length();
        const int M = t.length();
        
        s = "#" + s;
        t = "#" + t;
        
        // dp[i][j]: number of distinct subsequences of s[1 .. i] which equals t[1 .. j]
        vector<vector<long long>> dp(2, vector<long long>(M + 2));
        dp[0][0] = 1;
        dp[1][0] = 1;
        
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if(s[i] == t[j]){
                    dp[i % 2][j] += dp[(i - 1) % 2][j - 1];
                }
                // It is guaranteed the answer fits on a 32-bit signed integer => dp[i][j] <= INT_MAX
                dp[i % 2][j] = min(dp[i % 2][j], (long long)INT_MAX);
            }
        }
        
        return dp[N % 2][M];
    }
};