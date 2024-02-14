class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        // At (row)th iteration:
        //    dp[row % 2][col1][col2]: max number of collected cherries when
        //                             robot1 reaches (row, col1) and
        //                             robot2 reaches (row, col2)
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(COLS, vector<int>(COLS, -INF)));
        dp[0][0][COLS - 1] = grid[0][0] + grid[0][COLS - 1];
        
        for(int row = 0; row + 1 < ROWS; ++row){
            for(int col1 = 0; col1 < COLS; ++col1){
                for(int col2 = col1; col2 < COLS; ++col2){
                    dp[(row + 1) % 2][col1][col2] = -INF;
                }
            }

            for(int col1 = 0; col1 < COLS; ++col1){
                for(int col2 = col1; col2 < COLS; ++col2){
                    for(int nextCol1 = max(0, col1 - 1); nextCol1 <= min(COLS - 1, col1 + 1); ++nextCol1){
                        for(int nextCol2 = max(0, col2 - 1); nextCol2 <= min(COLS - 1, col2 + 1); ++nextCol2){
                            int c = grid[row + 1][nextCol1] + (int)(nextCol1 != nextCol2) * grid[row + 1][nextCol2];
                            dp[(row + 1) % 2][nextCol1][nextCol2] = max(dp[(row + 1) % 2][nextCol1][nextCol2],
                                                                        dp[row % 2][col1][col2] + c);
                        }
                    }
                }
            }
        }

        int res = 0;
        for(int col1 = 0; col1 < COLS; ++col1){
            for(int col2 = col1; col2 < COLS; ++col2){
                res = max(res, dp[(ROWS - 1) % 2][col1][col2]);
            }
        }

        return res;
    }
};