class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampRows, int stampCols) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int STAMP_SIZE = stampRows * stampCols;
        
        int prefSum[ROWS + 2][COLS + 2];
        int diff[ROWS + 2][COLS + 2];
        for(int row = 0; row <= ROWS + 1; ++row){
            for(int col = 0; col <= COLS + 1; ++col){
                prefSum[row][col] = 0;
                diff[row][col] = 0;
            }
        }
        
        for(int row = 1; row <= ROWS; ++row){
            for(int col = 1; col <= COLS; ++col){
                prefSum[row][col] = prefSum[row - 1][col] + prefSum[row][col - 1] - prefSum[row - 1][col - 1];
                if(grid[row - 1][col - 1] == 0){
                    prefSum[row][col] += 1;
                }
            }
        }
        
        for(int row = stampRows; row <= ROWS; ++row){
            for(int col = stampCols; col <= COLS; ++col){
                int zeros = prefSum[row][col] + prefSum[row - stampRows][col - stampCols] -
                            prefSum[row - stampRows][col] - prefSum[row][col - stampCols];
                if(zeros == STAMP_SIZE){
                    int row1 = row - stampRows + 1;
                    int row2 = row;
                    int col1 = col - stampCols + 1;
                    int col2 = col;
                    diff[row1][col1] += 1;
                    diff[row1][col2 + 1] -= 1;
                    diff[row2 + 1][col1] -= 1;
                    diff[row2 + 1][col2 + 1] += 1;
                }
            }
        }
        
        for(int row = 1; row <= ROWS; ++row){
            for(int col = 1; col <= COLS; ++col){
                diff[row][col] += diff[row][col - 1] + diff[row - 1][col] - diff[row - 1][col - 1];
                int stampsCount = diff[row][col];
                if(grid[row - 1][col - 1] == 0 && stampsCount == 0){
                    return false;
                }
            }
        }
        
        return true;
    }
};