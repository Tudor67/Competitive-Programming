class Solution {
private:
    int getVal(vector<vector<int>>& dp, int i, int j){
        if(i < 0 || j < 0){
            return 0;
        }
        return dp[i][j];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        const int L1 = text1.length();
        const int L2 = text2.length();

        // dp[i][j]: length of the max common subsequence of text1[0 .. i] and text2[0 .. j]
        vector<vector<int>> dp(L1, vector<int>(L2));
        for(int i = 0; i < L1; ++i){
            for(int j = 0; j < L2; ++j){
                if(text1[i] == text2[j]){
                    dp[i][j] = getVal(dp, i - 1, j - 1) + 1;
                }else{
                    dp[i][j] = max(getVal(dp, i - 1, j), getVal(dp, i, j - 1));
                }
            }
        }

        return dp[L1 - 1][L2 - 1];
    }
};