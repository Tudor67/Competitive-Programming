class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        // dp[row][col]: min falling path sum at (row, col)
        vector<vector<int>> dp(ROWS, vector<int>(COLS, INF));
        for(int col = 0; col < COLS; ++col){
            dp[0][col] = grid[0][col];
        }

        for(int row = 1; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int j = 0; j < COLS; ++j){
                    if(j != col){
                        dp[row][col] = min(dp[row][col], dp[row - 1][j] + grid[row][col]);
                    }
                }
            }
        }

        return *min_element(dp[ROWS - 1].begin(), dp[ROWS - 1].end());
    }
};