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

        // At ith iteration:
        //    dp[i % 2][j]: length of the max common subsequence of text1[0 .. i] and text2[0 .. j]
        vector<vector<int>> dp(2, vector<int>(L2));
        for(int i = 0; i < L1; ++i){
            for(int j = 0; j < L2; ++j){
                if(text1[i] == text2[j]){
                    dp[i % 2][j] = getVal(dp, (i - 1) % 2, j - 1) + 1;
                }else{
                    dp[i % 2][j] = max(getVal(dp, (i - 1) % 2, j), getVal(dp, i % 2, j - 1));
                }
            }
        }

        return dp[(L1 - 1) % 2][L2 - 1];
    }
};