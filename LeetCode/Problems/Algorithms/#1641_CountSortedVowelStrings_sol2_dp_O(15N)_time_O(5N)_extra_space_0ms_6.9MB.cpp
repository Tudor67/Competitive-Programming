class Solution {
public:
    int countVowelStrings(int n) {
        // dp[i][j] - number of lexicographically sorted vowel-strings of length i and with last letter equal to vowel[j]
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        
        for(int j = 0; j < 5; ++j){
            dp[1][j] = 1;
        }
        
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j < 5; ++j){
                for(int k = 0; k <= j; ++k){
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        
        return accumulate(dp[n].begin(), dp[n].end(), 0);
    }
};