class Solution {
public:
    int minDistance(string word1, string word2) {
        const int N = word1.length();
        const int M = word2.length();
        
        vector<vector<int>> dp(N + 1, vector<int>(M + 1));
        word1 = "#" + word1;
        word2 = "#" + word2;
        
        for(int i = 1; i <= N; ++i){
            dp[i][0] = i;
        }
        
        for(int j = 1; j <= M; ++j){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }
        
        return dp[N][M];
    }
};