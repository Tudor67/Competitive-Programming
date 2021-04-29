class Solution {
private:
    static bool isInside(int row, int col, vector<vector<int>>& obstacleGrid){
        return (0 <= row && row < (int)obstacleGrid.size() && 0 <= col && col < (int)obstacleGrid[0].size());
    }
    
    int solve(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo){
        if(!isInside(row, col, obstacleGrid) || obstacleGrid[row][col] == 1){
            return 0;
        }
        if(row == 0 && col == 0){
            memo[row][col] = 1;
        }
        if(memo[row][col] == -1){
            memo[row][col] = solve(row - 1, col, obstacleGrid, memo) + solve(row, col - 1, obstacleGrid, memo);
        }
        return memo[row][col];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int ROWS = obstacleGrid.size();
        const int COLS = obstacleGrid[0].size();
        vector<vector<int>> memo(ROWS, vector<int>(COLS, -1));
        return solve(ROWS - 1, COLS - 1, obstacleGrid, memo);
    }
};