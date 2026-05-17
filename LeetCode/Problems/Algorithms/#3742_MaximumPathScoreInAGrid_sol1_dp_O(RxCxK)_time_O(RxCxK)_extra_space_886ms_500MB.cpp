class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}};

        // dp[row][col][c]: max score to reach (row, col) from (0, 0) with cost c
        vector<vector<vector<int>>> dp(ROWS, vector<vector<int>>(COLS, vector<int>(k + 1, -1)));

        dp[0][0][0] = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int cost = 0; cost <= k; ++cost){
                    if(dp[row][col][cost] == -1){
                        continue;
                    }
                    for(const auto& [rowDir, colDir]: DIRECTIONS){
                        int nextRow = row + rowDir;
                        int nextCol = col + colDir;
                        if(nextRow < ROWS && nextCol < COLS){
                            int nextCost = cost + min(1, grid[nextRow][nextCol]);
                            if(nextCost <= k){
                                dp[nextRow][nextCol][nextCost] = max(dp[nextRow][nextCol][nextCost],
                                                                     dp[row][col][cost] + grid[nextRow][nextCol]);
                            }
                        }
                    }
                }
            }
        }

        return *max_element(dp[ROWS - 1][COLS - 1].begin(), dp[ROWS - 1][COLS - 1].end());
    }
};