class Solution {
public:
    bool isMatch(string s, string p) {
        s = "#" + s;
        p = "#" + p;
        
        int n = (int)s.length() - 1;
        int m = (int)p.length() - 1;
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // dp[i][j] = 1, if p[0 .. j] matches s[0 .. i]
        //            0, if p[0 .. j] doesn't match s[0 .. i]
        
        // Step 1: s[0] = p[0] = '#' (empty sequence) => dp[0][0] = true
        // Also s[0] = p[0 .. j] if and only if p[0 .. j] = "#*** .. *" => dp[0][j] = true
        dp[0][0] = true;
        for(int j = 1; j <= m && p[j] == '*'; ++j){
            dp[0][j] = true;
        }
        
        // Step 2: build dp[i][j] for i >= 1
        // dp[i][j] = dp[i - 1][j - 1],             if (s[i] == p[j]) || (p[j] == '?')
        //            dp[i][j - 1] || dp[i - 1][j], if (p[j] == '*')
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                bool match1 = ((s[i] == p[j] || p[j] == '?') && dp[i - 1][j - 1]);
                bool match2 = (p[j] == '*' && (dp[i][j - 1] || dp[i - 1][j]));
                dp[i][j] = (match1 || match2);
            }
        }
        
        return dp[n][m];
    }
};