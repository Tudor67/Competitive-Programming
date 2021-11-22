class Solution {
public:
    int uniquePaths(int m, int n) {
        const int ROWS = min(m, n);
        const int COLS = max(m, n);
        
        // dp[row][col]: number of unique paths from (1, 1) to (row, col)
        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1, 0));
        for(int row = 1; row <= ROWS; ++row){
            for(int col = 1; col <= COLS; ++col){
                if(row == 1 && col == 1){
                    dp[row][col] = 1;
                }else{
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
                }
            }
        }
        
        return dp[ROWS][COLS];
    }
};