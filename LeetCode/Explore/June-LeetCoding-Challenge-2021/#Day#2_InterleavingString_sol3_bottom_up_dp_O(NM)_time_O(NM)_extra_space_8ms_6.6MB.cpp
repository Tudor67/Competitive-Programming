class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int N1 = s1.length();
        const int N2 = s2.length();
        const int N3 = s3.length();
        
        if(N1 + N2 != N3){
            return false;
        }
        
        s1 = "#" + s1;
        s2 = "#" + s2;
        s3 = "#" + s3;
        
        vector<vector<bool>> dp(N1 + 1, vector<bool>(N2 + 1, false));
        // dp[i][j]: true, if s3[1 .. (i + j)] is formed by an interleaving of s1[1 .. i] and s2[1 .. j]
        //           false, otherwise
        
        for(int i = 0; i <= N1; ++i){
            for(int j = 0; j <= N2; ++j){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }else if(i == 0){
                    dp[0][j] = dp[0][j - 1] && (s2[j] == s3[j]);
                }else if(j == 0){
                    dp[i][0] = dp[i - 1][0] && (s1[i] == s3[i]);
                }else{
                    dp[i][j] = (dp[i - 1][j] && (s1[i] == s3[i + j]))
                                 ||
                               (dp[i][j - 1] && (s2[j] == s3[i + j]));
                }
            }
        }
        
        return dp[N1][N2];
    }
};