class Solution {
public:
    bool isMatch(string s, string p) {
        // '#' - notation for empty char
        s = "#" + s;
        p = "#" + p;
        
        int n = (int)s.length() - 1;
        int m = (int)p.length() - 1;
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));  
        // dp[i][j]: 1, if s[0 .. i] is a match of p[0 .. j]
        //           0, if s[0 .. i] is not a match of p[0 .. j]
        
        // s[0] = p[0] = '#' => dp[0][0] = true
        // Also s[0] = p[0 .. j] if and only if p[0 .. j] is ".*.*.* ... .*"
        dp[0][0] = true;
        for(int j = 2; j <= m && p[j] == '*'; j += 2){
            dp[0][j] = true;
        }
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                bool match1 = (s[i] == p[j] || p[j] == '.') && dp[i - 1][j - 1];
                bool match2 = (p[j] == '*' && (dp[i][j - 1] || (j >= 2 && dp[i][j - 2])));
                bool match3 = (p[j] == '*' && (s[i] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j]);
                dp[i][j] = (match1 || match2 || match3);
            }
        }     
        
        return dp[n][m];
    }
};