class Solution {
public:
    int uniquePaths(int m, int n) {
        const int ROWS = m;
        const int COLS = n;

        // At (row)th iteration:
        //    dp[row % 2][col]: number of unique paths from (0, 0) to (row, col)
        vector<vector<int>> dp(2, vector<int>(COLS + 1));
        dp[0][1] = 1;
        for(int row = 1; row <= ROWS; ++row){
            for(int col = 1; col <= COLS; ++col){
                dp[row % 2][col] = dp[(row - 1) % 2][col] + dp[row % 2][col - 1];
            }
        }

        return dp[ROWS % 2][COLS];
    }
};