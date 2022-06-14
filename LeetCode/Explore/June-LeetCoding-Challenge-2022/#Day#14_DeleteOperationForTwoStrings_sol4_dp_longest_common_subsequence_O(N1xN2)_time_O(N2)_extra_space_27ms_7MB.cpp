class Solution {
private:
    int valAt(vector<vector<int>>& v, int i, int j){
        if(0 <= i && i < (int)v.size() && 0 <= j && j < (int)v[0].size()){
            return v[i][j];
        }
        return 0;
    }
    
public:
    int minDistance(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();
        
        // At step i:
        //    dp[i % 2][j]: length of the longest common subsequence of word1[0 .. i] and word2[0 .. j]
        vector<vector<int>> dp(2, vector<int>(N2));
        for(int i = 0; i < N1; ++i){
            for(int j = 0; j < N2; ++j){
                if(word1[i] == word2[j]){
                    dp[i % 2][j] = 1 + valAt(dp, (i - 1) % 2, j - 1);
                }else{
                    dp[i % 2][j] = max(valAt(dp, (i - 1) % 2, j), valAt(dp, i % 2, j - 1));
                }
            }
        }
        
        return (N1 + N2) - 2 * dp[(N1 - 1) % 2][N2 - 1];
    }
};