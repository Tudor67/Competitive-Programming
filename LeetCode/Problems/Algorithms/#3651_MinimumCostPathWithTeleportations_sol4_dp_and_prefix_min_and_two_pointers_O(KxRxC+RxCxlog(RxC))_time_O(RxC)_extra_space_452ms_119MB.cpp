class Solution {
private:
    void minimize(int& a, int b){
        a = min(a, b);
    }

public:
    int minCost(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        // At t'th iteration:
        // dp[row][col]: min cost to reach cell (row, col)
        //               using at most t teleportations
        vector<vector<int>> dp(ROWS, vector<int>(COLS, INF));
        dp[0][0] = 0;
        
        vector<array<int, 3>> sortedCells;
        sortedCells.reserve(ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                sortedCells.push_back({grid[row][col], row, col});
            }
        }

        sort(sortedCells.rbegin(), sortedCells.rend());

        for(int t = 0; t <= k; ++t){
            if(t >= 1){
                int l = 0;
                int prefMin = INF;
                while(l < (int)sortedCells.size()){
                    int r = l;
                    while(r < (int)sortedCells.size() && sortedCells[l][0] == sortedCells[r][0]){
                        const auto& [_, row, col] = sortedCells[r];
                        minimize(prefMin, dp[row][col]);
                        r += 1;
                    }

                    for(int i = l; i < r; ++i){
                        const auto& [_, row, col] = sortedCells[i];
                        minimize(dp[row][col], prefMin);
                    }

                    l = r;
                }
            }

            for(int row = 0; row < ROWS; ++row){
                for(int col = 0; col < COLS; ++col){
                    if(row - 1 >= 0){
                        minimize(dp[row][col], dp[row - 1][col] + grid[row][col]);
                    }
                    if(col - 1 >= 0){
                        minimize(dp[row][col], dp[row][col - 1] + grid[row][col]);
                    }
                }
            }
        }

        return dp[ROWS - 1][COLS - 1];
    }
};