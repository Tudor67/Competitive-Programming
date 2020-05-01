class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n = text1.length();
        const int m = text2.length();
        
        text1 = "#" + text1;
        text2 = "#" + text2;
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};