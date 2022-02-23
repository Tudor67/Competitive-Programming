class Solution {
public:
    string largestMerge(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();
        
        word1 = "#" + word1;
        word2 = "#" + word2;
        
        vector<vector<string>> dp(N1 + 1, vector<string>(N2 + 1));
        for(int i = 1; i <= N1; ++i){
            dp[i][0] = word1.substr(1, i);
        }
        
        for(int j = 1; j <= N2; ++j){
            dp[0][j] = word2.substr(1, j);
        }
        
        for(int i = 1; i <= N1; ++i){
            for(int j = 1; j <= N2; ++j){
                dp[i][j] = max(dp[i - 1][j] + word1[i], dp[i][j - 1] + word2[j]);
            }
        }
        
        return dp[N1][N2];
    }
};