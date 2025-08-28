class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int minRow = ROWS;
        int maxRow = -1;
        int minCol = COLS;
        int maxCol = -1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    minRow = min(minRow, row);
                    maxRow = max(maxRow, row);
                    minCol = min(minCol, col);
                    maxCol = max(maxCol, col);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};