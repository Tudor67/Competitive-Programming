class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        dp[0][0] = grid[0][0];
        for(int j = 1; j < m; ++j){
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }
        
        for(int i = 1; i < n; ++i){
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[n - 1][m - 1];
    }
};