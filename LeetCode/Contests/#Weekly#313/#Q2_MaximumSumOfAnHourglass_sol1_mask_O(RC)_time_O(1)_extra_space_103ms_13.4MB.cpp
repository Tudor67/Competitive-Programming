class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        const vector<vector<int>> MASK = {{1, 1, 1}, {0, 1, 0}, {1, 1, 1}};
        const int MASK_ROWS = MASK.size();
        const int MASK_COLS = MASK[0].size();
        
        int res = 0;
        for(int row = 0; row + MASK_ROWS - 1 < ROWS; ++row){
            for(int col = 0; col + MASK_COLS - 1 < COLS; ++col){
                int sum = 0;
                for(int maskRow = 0; maskRow < MASK_ROWS; ++maskRow){
                    for(int maskCol = 0; maskCol < MASK_COLS; ++maskCol){
                        sum += MASK[maskRow][maskCol] * grid[row + maskRow][col + maskCol];
                    }
                }
                res = max(res, sum);
            }
        }
        
        return res;
    }
};