class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int N1 = text1.length();
        const int N2 = text2.length();

        // At (N1 - i)th iteration:
        //    dp[i % 2][j]: length of the longest common subsequence of text1[i .. N1 - 1] and text2[j .. N2 - 1]
        vector<vector<int>> dp(2, vector<int>(N2 + 1));
        for(int i = N1 - 1; i >= 0; --i){
            for(int j = N2 - 1; j >= 0; --j){
                if(text1[i] == text2[j]){
                    dp[i % 2][j] = 1 + dp[(i + 1) % 2][j + 1];
                }else{
                    dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};