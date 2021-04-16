class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[k][n]: min number of moves to determine f
        //           with k eggs and n floors
        vector<vector<int>> dp(2, vector<int>(n + 1));
        
        for(int j = 0; j <= n; ++j){
            dp[1][j] = j;
        }
        
        for(int i = 2; i <= k; ++i){
            dp[i % 2] = dp[(i - 1) % 2];
            int f = 1;
            for(int j = 1; j <= n; ++j){
                while(f < j && max(dp[(i - 1) % 2][f - 1], dp[i % 2][j - f]) > max(dp[(i - 1) % 2][f], dp[i % 2][j - f - 1])){
                    f += 1;
                }
                dp[i % 2][j] = min(1 + max(dp[(i - 1) % 2][f - 1], dp[i % 2][j - f]), dp[i % 2][j]);
            }
        }
        
        return dp[k % 2][n];
    }
};