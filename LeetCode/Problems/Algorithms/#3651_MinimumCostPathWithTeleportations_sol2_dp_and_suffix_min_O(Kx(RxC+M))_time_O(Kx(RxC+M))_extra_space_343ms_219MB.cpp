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

        // dp[t][row][col]: min cost to reach cell (row, col)
        //                  using at most t teleports
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(ROWS, vector<int>(COLS, INF)));
        dp[0][0][0] = 0;

        int maxVal = grid[0][0];
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                maxVal = max(maxVal, grid[row][col]);
            }
        }

        vector<vector<int>> suffMin(k + 1, vector<int>(maxVal + 1, INF));
        fill(suffMin[0].begin(), suffMin[0].begin() + grid[0][0] + 1, 0);

        for(int t = 0; t <= k; ++t){
            for(int row = 0; row < ROWS; ++row){
                for(int col = 0; col < COLS; ++col){
                    if(row - 1 >= 0){
                        minimize(dp[t][row][col], dp[t][row - 1][col] + grid[row][col]);
                    }

                    if(col - 1 >= 0){
                        minimize(dp[t][row][col], dp[t][row][col - 1] + grid[row][col]);
                    }
                    
                    if(t >= 1){
                        minimize(dp[t][row][col], suffMin[t - 1][grid[row][col]]);
                    }

                    minimize(suffMin[t][grid[row][col]], dp[t][row][col]);
                }
            }

            for(int val = maxVal - 1; val >= 0; --val){
                minimize(suffMin[t][val], suffMin[t][val + 1]);
            }
        }

        return dp[k][ROWS - 1][COLS - 1];
    }
};