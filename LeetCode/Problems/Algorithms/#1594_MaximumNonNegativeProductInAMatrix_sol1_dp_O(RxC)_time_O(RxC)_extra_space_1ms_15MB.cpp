class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<long long>> mn(ROWS, vector<long long>(COLS));
        vector<vector<long long>> mx(ROWS, vector<long long>(COLS));

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 && col == 0){
                    mn[row][col] = grid[row][col];
                    mx[row][col] = grid[row][col];
                }else if(row == 0){
                    mn[row][col] = min(grid[row][col] * mn[row][col - 1],
                                       grid[row][col] * mx[row][col - 1]);
                    mx[row][col] = max(grid[row][col] * mn[row][col - 1],
                                       grid[row][col] * mx[row][col - 1]);
                }else if(col == 0){
                    mn[row][col] = min(grid[row][col] * mn[row - 1][col],
                                       grid[row][col] * mx[row - 1][col]);
                    mx[row][col] = max(grid[row][col] * mn[row - 1][col],
                                       grid[row][col] * mx[row - 1][col]);
                }else{
                    mn[row][col] = min(grid[row][col] * min(mn[row - 1][col], mn[row][col - 1]),
                                       grid[row][col] * max(mx[row - 1][col], mx[row][col - 1]));
                    mx[row][col] = max(grid[row][col] * min(mn[row - 1][col], mn[row][col - 1]),
                                       grid[row][col] * max(mx[row - 1][col], mx[row][col - 1]));
                }
            }
        }

        if(mx[ROWS - 1][COLS - 1] >= 0){
            return mx[ROWS - 1][COLS - 1] % 1'000'000'007;
        }

        return -1;
    }
};