class Solution {
public:
    int uniquePaths(int m, int n) {
        const int ROWS = max(m, n);
        const int COLS = min(m, n);
        
        // dp[row][col]: number of unique paths from (1, 1) to (row, col)
        vector<vector<int>> dp(2, vector<int>(COLS + 1, 0));
        for(int row = 1; row <= ROWS; ++row){
            for(int col = 1; col <= COLS; ++col){
                if(row == 1 && col == 1){
                    dp[row % 2][col] = 1;
                }else{
                    dp[row % 2][col] = dp[(row - 1) % 2][col] + dp[row % 2][col - 1];
                }
            }
        }
        
        return dp[ROWS % 2][COLS];
    }
};