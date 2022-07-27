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
        
        // At ith iteration:
        //    dp[i % 2][j]: true, if first (i + j) chars of s3 are formed by an interleaving
        //                    of first i chars of s1 and first j chars of s2
        //                  false, otherwise
        vector<vector<bool>> dp(2, vector<bool>(M + 1, false));
        for(int i = 0; i <= N; ++i){
            for(int j = 0; j <= M; ++j){
                dp[i % 2][j] = false;
                if(i == 0 && j == 0){
                    dp[0][0] = true;
                }
                if(s1[i] == s3[i + j] && i - 1 >= 0){
                    dp[i % 2][j] = dp[i % 2][j] || dp[(i - 1) % 2][j];
                }
                if(s2[j] == s3[i + j] && j - 1 >= 0){
                    dp[i % 2][j] = dp[i % 2][j] || dp[i % 2][j - 1];
                }
            }
        }
        
        return dp[N % 2][M];
    }
};