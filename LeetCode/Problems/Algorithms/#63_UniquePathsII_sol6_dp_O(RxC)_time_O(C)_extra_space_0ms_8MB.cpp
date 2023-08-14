class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int ROWS = obstacleGrid.size();
        const int COLS = obstacleGrid[0].size();

        // At (row)th iteration:
        //    dp[row % 2][col]: number of unique paths from (0, 0) to (row, col)
        vector<vector<int>> dp(2, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                dp[row % 2][col] = 0;
                if(obstacleGrid[row][col] == 1){
                    // ignore this cell
                }else if(row == 0 && col == 0){
                    dp[row % 2][col] = 1;
                }else if(row == 0){
                    dp[row % 2][col] = dp[row % 2][col - 1];
                }else if(col == 0){
                    dp[row % 2][col] = dp[(row - 1) % 2][col];
                }else if(dp[(row - 1) % 2][col] <= INT_MAX - dp[row % 2][col - 1]){
                    dp[row % 2][col] = dp[(row - 1) % 2][col] + dp[row % 2][col - 1];
                }
            }
        }

        return dp[(ROWS - 1) % 2][COLS - 1];
    }
};