class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        k %= (ROWS * COLS);

        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int index = (row * COLS + col - k + ROWS * COLS) % (ROWS * COLS);
                res[row][col] = grid[index / COLS][index % COLS];
            }
        }

        return res;
    }
};