class Solution {
public:
    int uniquePaths(int m, int n) {
        const int ROWS = m;
        const int COLS = n;

        // dp[row][col]: number of unique paths from (0, 0) to (row, col)
        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1));
        dp[0][1] = 1;
        for(int row = 1; row <= ROWS; ++row){
            for(int col = 1; col <= COLS; ++col){
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }

        return dp[ROWS][COLS];
    }
};