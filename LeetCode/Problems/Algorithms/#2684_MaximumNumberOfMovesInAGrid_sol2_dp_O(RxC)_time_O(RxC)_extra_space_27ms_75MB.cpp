class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        // dp[row][col]: max number of visited cells from the first column to the cell (row, col)
        vector<vector<int>> dp(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            dp[row][0] = 1;
        }

        int res = 0;
        for(int col = 1; col < COLS; ++col){
            for(int row = 0; row < ROWS; ++row){
                for(int rowShift = -1; rowShift <= 1; ++rowShift){
                    int prevRow = row + rowShift;
                    if(0 <= prevRow && prevRow < ROWS){
                        if(dp[prevRow][col - 1] >= 1 && grid[prevRow][col - 1] < grid[row][col]){
                            dp[row][col] = max(dp[row][col], dp[prevRow][col - 1] + 1);
                        }
                    }
                }
                res = max(res, dp[row][col] - 1);
            }
        }

        return res;
    }
};