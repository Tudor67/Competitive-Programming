class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> dp(ROWS, vector<int>(COLS));
        dp[0][0] = grid[0][0];
        for(int col = 1; col < COLS; ++col){
            dp[0][col] = dp[0][col - 1] + grid[0][col];
        }

        for(int row = 1; row < ROWS; ++row){
            dp[row][0] = dp[row - 1][0] + grid[row][0];
        }

        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
            }
        }

        return dp[ROWS - 1][COLS - 1];
    }
};