class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MODULO = 1'000'000'007;

        // dp[rem][row][col]: number of paths from (0, 0) to (row, col)
        //                    with (pathSum % k == rem)
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(ROWS, vector<int>(COLS)));
        dp[grid[0][0] % k][0][0] = 1;

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int rem = 0; rem < k; ++rem){
                    if(col + 1 < COLS){
                        add(dp[(rem + grid[row][col + 1]) % k][row][col + 1], dp[rem][row][col], MODULO);
                    }
                    if(row + 1 < ROWS){
                        add(dp[(rem + grid[row + 1][col]) % k][row + 1][col], dp[rem][row][col], MODULO);
                    }
                }
            }
        }

        return dp[0][ROWS - 1][COLS - 1];
    }
};