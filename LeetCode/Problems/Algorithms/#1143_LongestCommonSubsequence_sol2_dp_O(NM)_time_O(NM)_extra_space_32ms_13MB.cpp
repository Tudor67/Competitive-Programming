class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int N = text1.length();
        const int M = text2.length();
        
        text1 = "#" + text1;
        text2 = "#" + text2;
        
        vector<vector<int>> dp(N + 1, vector<int>(M + 1));
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[N][M];
    }
};