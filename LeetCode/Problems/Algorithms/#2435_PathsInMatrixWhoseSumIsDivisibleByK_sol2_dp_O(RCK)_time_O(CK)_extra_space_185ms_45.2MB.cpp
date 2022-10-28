class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MODULO = 1e9 + 7;
        
        // At iteration with number row:
        //    dp[row % 2][col][rem]: number of paths from (0, 0) to (row, col)
        //                           with (pathSum % k == rem)
        int dp[2][COLS][k];
        for(int col = 0; col < COLS; ++col){
            for(int rem = 0; rem < k; ++rem){
                dp[0][col][rem] = 0;
            }
        }
        
        int prefSum = 0;
        for(int col = 0; col < COLS; ++col){
            prefSum += grid[0][col];
            prefSum %= k;
            dp[0][col][prefSum] = 1;
        }
        
        int firstColPrefSum = grid[0][0] % k;
        for(int row = 1; row < ROWS; ++row){
            for(int rem = 0; rem < k; ++rem){
                dp[row % 2][0][rem] = 0;
            }
            firstColPrefSum += grid[row][0];
            firstColPrefSum %= k;
            dp[row % 2][0][firstColPrefSum] = 1;
            for(int col = 1; col < COLS; ++col){
                for(int rem = 0; rem < k; ++rem){
                    dp[row % 2][col][(rem + grid[row][col]) % k] = (dp[(row - 1) % 2][col][rem] +
                                                                    dp[row % 2][col - 1][rem]) % MODULO;
                }
            }
        }
        
        return dp[(ROWS - 1) % 2][COLS - 1][0];
    }
};