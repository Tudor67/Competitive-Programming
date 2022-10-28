class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MODULO = 1e9 + 7;
        
        // dp[row][col][rem]: number of paths from (0, 0) to (row, col)
        //                    with (pathSum % k == rem)
        int dp[ROWS][COLS][k];
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int rem = 0; rem < k; ++rem){
                    dp[row][col][rem] = 0;
                }
            }
        }
        
        int prefSum = 0;
        for(int col = 0; col < COLS; ++col){
            prefSum += grid[0][col];
            prefSum %= k;
            dp[0][col][prefSum] = 1;
        }
        
        prefSum = 0;
        for(int row = 0; row < ROWS; ++row){
            prefSum += grid[row][0];
            prefSum %= k;
            dp[row][0][prefSum] = 1;
        }
        
        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                for(int rem = 0; rem < k; ++rem){
                    dp[row][col][(rem + grid[row][col]) % k] = (dp[row - 1][col][rem] +
                                                                dp[row][col - 1][rem]) % MODULO;
                }
            }
        }
        
        return dp[ROWS - 1][COLS - 1][0];
    }
};