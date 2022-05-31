class Solution {
public:
    int countVowelStrings(int N) {
        const int V = 5;
        
        // dp[i][j]: number of lexicographically sorted vowel-strings of length i
        //           with the last letter equal to the jth vowel
        vector<vector<int>> dp(N + 1, vector<int>(V));
        
        for(int j = 0; j < V; ++j){
            dp[1][j] = 1;
        }
        
        for(int i = 2; i <= N; ++i){
            for(int j = 0; j < V; ++j){
                for(int k = 0; k <= j; ++k){
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        
        return accumulate(dp[N].begin(), dp[N].end(), 0);
    }
};