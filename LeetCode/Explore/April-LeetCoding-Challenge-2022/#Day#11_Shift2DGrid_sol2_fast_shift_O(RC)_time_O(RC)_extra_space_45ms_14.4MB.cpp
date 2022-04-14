class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<int> values(ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                values[row * COLS + col] = grid[row][col];
            }
        }
        
        k %= (ROWS * COLS);
        reverse(values.begin(), values.end());
        reverse(values.begin(), values.begin() + k);
        reverse(values.begin() + k, values.end());
        
        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[row][col] = values[row * COLS + col];
            }
        }
        
        return res;
    }
};