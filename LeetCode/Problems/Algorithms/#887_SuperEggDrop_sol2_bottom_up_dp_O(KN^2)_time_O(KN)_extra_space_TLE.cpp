class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[k][n]: min number of moves to determine f
        //           with k eggs and n floors
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        
        for(int j = 0; j <= n; ++j){
            dp[1][j] = j;
        }
        
        for(int i = 2; i <= k; ++i){
            dp[i] = dp[i - 1];
            for(int j = 1; j <= n; ++j){
                for(int f = 1; f <= j - 1; ++f){
                    dp[i][j] = min(1 + max(dp[i - 1][f - 1], dp[i][j - f]), dp[i][j]);
                }
            }
        }
        
        return dp[k][n];
    }
};