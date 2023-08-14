class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int ROWS = obstacleGrid.size();
        const int COLS = obstacleGrid[0].size();

        // dp[row][col]: number of unique paths from (0, 0) to (row, col)
        vector<vector<int>> dp(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(obstacleGrid[row][col] == 1){
                    // ignore this cell
                }else if(row == 0 && col == 0){
                    dp[row][col] = 1;
                }else if(row == 0){
                    dp[row][col] = dp[row][col - 1];
                }else if(col == 0){
                    dp[row][col] = dp[row - 1][col];
                }else if(dp[row - 1][col] <= INT_MAX - dp[row][col - 1]){
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
                }
            }
        }

        return dp[ROWS - 1][COLS - 1];
    }
};