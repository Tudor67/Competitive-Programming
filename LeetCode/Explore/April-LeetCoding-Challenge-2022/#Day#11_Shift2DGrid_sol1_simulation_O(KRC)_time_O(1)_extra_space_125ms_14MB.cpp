class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        k %= (ROWS * COLS);
        
        vector<vector<int>> res = grid;
        for(int iteration = 1; iteration <= k; ++iteration){
            int lastVal = res[ROWS - 1][COLS - 1];
            for(int row = ROWS - 1; row >= 0; --row){
                for(int col = COLS - 1; col >= 0; --col){
                    int idx = row * COLS + col;
                    int prevIdx = idx - 1;
                    if(prevIdx == -1){
                        res[row][col] = lastVal;
                    }else{
                        int prevRow = prevIdx / COLS;
                        int prevCol = prevIdx % COLS;
                        res[row][col] = res[prevRow][prevCol];
                    }
                }
            }
        }
        
        return res;
    }
};