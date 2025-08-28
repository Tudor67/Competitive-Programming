class Solution {
private:
    int computeMinArea(const vector<vector<int>>& GRID,
                       const int FIRST_ROW, const int FIRST_COL, const int LAST_ROW, const int LAST_COL){
        int minRow = LAST_ROW;
        int minCol = LAST_COL;
        int maxRow = -1;
        int maxCol = -1;
        for(int row = FIRST_ROW; row <= LAST_ROW; ++row){
            for(int col = FIRST_COL; col <= LAST_COL; ++col){
                if(GRID[row][col] == 1){
                    minRow = min(minRow, row);
                    minCol = min(minCol, col);
                    maxRow = max(maxRow, row);
                    maxCol = max(maxCol, col);
                }
            }
        }
        if(minRow > maxRow){
            return 0;
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int minAreaSum = ROWS * COLS;

        for(int col1 = 0; col1 < COLS; ++col1){
            for(int col2 = col1 + 1; col2 < COLS; ++col2){
                minAreaSum = min(minAreaSum, computeMinArea(grid, 0, 0, ROWS - 1, col1) +
                                             computeMinArea(grid, 0, col1 + 1, ROWS - 1, col2) +
                                             computeMinArea(grid, 0, col2 + 1, ROWS - 1, COLS - 1));
            }
        }

        for(int row1 = 0; row1 < ROWS; ++row1){
            for(int row2 = row1 + 1; row2 < ROWS; ++row2){
                minAreaSum = min(minAreaSum, computeMinArea(grid, 0, 0, row1, COLS - 1) +
                                             computeMinArea(grid, row1 + 1, 0, row2, COLS - 1) +
                                             computeMinArea(grid, row2 + 1, 0, ROWS - 1, COLS - 1));
            }
        }

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                minAreaSum = min(minAreaSum, computeMinArea(grid, 0, 0, ROWS - 1, col) +
                                             computeMinArea(grid, 0, col + 1, row, COLS - 1) +
                                             computeMinArea(grid, row + 1, col + 1, ROWS - 1, COLS - 1));
                minAreaSum = min(minAreaSum, computeMinArea(grid, 0, 0, row, COLS - 1) +
                                             computeMinArea(grid, row + 1, 0, ROWS - 1, col) +
                                             computeMinArea(grid, row + 1, col + 1, ROWS - 1, COLS - 1));
                minAreaSum = min(minAreaSum, computeMinArea(grid, 0, 0, row, col) +
                                             computeMinArea(grid, row + 1, 0, ROWS - 1, col) +
                                             computeMinArea(grid, 0, col + 1, ROWS - 1, COLS - 1));
                minAreaSum = min(minAreaSum, computeMinArea(grid, 0, 0, row, col) +
                                             computeMinArea(grid, 0, col + 1, row, COLS - 1) +
                                             computeMinArea(grid, row + 1, 0, ROWS - 1, COLS - 1));
            }
        }

        return minAreaSum;
    }
};