class Solution {
private:
    int getVal(int row, int col, vector<vector<int>>& matrix){
        if(row < 0 || row >= (int)matrix.size() || col < 0 || col >= (int)matrix[0].size()){
            return 0;
        }
        return matrix[row][col];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int ROWS = obstacleGrid.size();
        const int COLS = obstacleGrid[0].size();
        
        vector<vector<int>> dp(2, vector<int>(COLS, 0));
        if(obstacleGrid[0][0] == 0){
            dp[0][0] = 1;
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(obstacleGrid[row][col] == 0){
                    dp[row % 2][col] += getVal((row - 1) % 2, col, dp);
                    dp[row % 2][col] += getVal(row % 2, col - 1, dp);
                }
            }
            fill(dp[(row + 1) % 2].begin(), dp[(row + 1) % 2].end(), 0);
        }
        
        return dp[(ROWS - 1) % 2][COLS - 1];
    }
};