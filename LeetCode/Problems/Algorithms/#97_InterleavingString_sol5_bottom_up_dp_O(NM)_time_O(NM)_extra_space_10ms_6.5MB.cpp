class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        
        const int N = s1.length();
        const int M = s2.length();
        
        s1 = "#" + s1;
        s2 = "#" + s2;
        s3 = "#" + s3;
        
        // dp[i][j]: true, if first (i + j) chars of s3 are formed by an interleaving
        //                 of first i chars of s1 and first j chars of s2
        //           false, otherwise
        vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= N; ++i){
            for(int j = 0; j <= M; ++j){
                if(s1[i] == s3[i + j] && i - 1 >= 0){
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if(s2[j] == s3[i + j] && j - 1 >= 0){
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        
        return dp[N][M];
    }
};