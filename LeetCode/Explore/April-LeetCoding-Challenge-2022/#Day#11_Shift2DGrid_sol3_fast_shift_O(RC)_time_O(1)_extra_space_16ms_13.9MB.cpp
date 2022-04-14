class Solution {
private:
    void reverse(vector<vector<int>>& grid, int idx1, int idx2){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        while(idx1 < idx2){
            int row1 = idx1 / COLS;
            int col1 = idx1 % COLS;
            int row2 = idx2 / COLS;
            int col2 = idx2 % COLS;
            swap(grid[row1][col1], grid[row2][col2]);
            idx1 += 1;
            idx2 -= 1;
        }
    }
    
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        k %= (ROWS * COLS);
        
        vector<vector<int>> res = grid;
        reverse(res, 0, ROWS * COLS - 1);
        reverse(res, 0, k - 1);
        reverse(res, k, ROWS * COLS - 1);
        
        return res;
    }
};