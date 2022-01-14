class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e8;
        
        // dp[row][col1][col2]: max sum when robot1 is at (row, col1)
        //                               and robot2 is at (row, col2)
        int dp[2][COLS][COLS];
        for(int row = 0; row < 2; ++row){
            for(int col1 = 0; col1 < COLS; ++col1){
                for(int col2 = 0; col2 < COLS; ++col2){
                    dp[row][col1][col2] = -INF;
                }
            }
        }
        
        dp[0][0][COLS - 1] = grid[0][0] + grid[0][COLS - 1];
        for(int row = 1; row < ROWS; ++row){
            for(int col1 = 0; col1 < COLS; ++col1){
                for(int col2 = 0; col2 < COLS; ++col2){
                    int prevMaxSum = -INF;
                    int prevRow = row - 1;
                    for(int prevCol1 = max(0, col1 - 1); prevCol1 <= min(COLS - 1, col1 + 1); ++prevCol1){
                        for(int prevCol2 = max(0, col2 - 1); prevCol2 <= min(COLS - 1, col2 + 1); ++prevCol2){
                            prevMaxSum = max(prevMaxSum, dp[prevRow % 2][prevCol1][prevCol2]);
                        }
                    }
                    dp[row % 2][col1][col2] = prevMaxSum + grid[row][col1] + ((int)(col1 != col2)) * grid[row][col2];
                }
            }
        }
        
        int maxSum = 0;
        for(int col1 = 0; col1 < COLS; ++col1){
            for(int col2 = 0; col2 < COLS; ++col2){
                maxSum = max(maxSum, dp[(ROWS - 1) % 2][col1][col2]);
            }
        }
        
        return maxSum;
    }
};