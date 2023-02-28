class Solution {
public:
    int minDistance(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();

        word1 = "$" + word1;
        word2 = "$" + word2;

        // At ith iteration:
        //    dp[i % 2][j]: min number of operations to convert word1[1 .. i] to word2[1 .. j]
        vector<vector<int>> dp(2, vector<int>(N2 + 1));
        for(int j = 0; j <= N2; ++j){
            dp[0][j] = j;
        }

        for(int i = 1; i <= N1; ++i){
            dp[i % 2][0] = i;
            for(int j = 1; j <= N2; ++j){
                if(word1[i] == word2[j]){
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                }else{
                    dp[i % 2][j] = 1 + min({dp[(i - 1) % 2][j], dp[i % 2][j - 1], dp[(i - 1) % 2][j - 1]});
                }
            }
        }

        return dp[N1 % 2][N2];
    }
};