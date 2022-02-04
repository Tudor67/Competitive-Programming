class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampRows, int stampCols) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int STAMP_SIZE = stampRows * stampCols;
        
        int prefSum[ROWS + 2][COLS + 2];
        bool can[ROWS + 2][COLS + 2];
        for(int row = 0; row <= ROWS; ++row){
            for(int col = 0; col <= COLS; ++col){
                prefSum[row][col] = 0;
                can[row][col] = false;
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
                    for(int i = row; i >= row - stampRows + 1 && !can[i][col]; --i){
                        for(int j = col; j >= col - stampCols + 1 && !can[i][j]; --j){
                            can[i][j] = true;
                        }
                    }
                    for(int i = row - stampRows + 1; i <= row && !can[i][col - stampCols + 1]; ++i){
                        for(int j = col - stampCols + 1; j <= col && !can[i][j]; ++j){
                            can[i][j] = true;
                        }
                    }
                }
            }
        }
        
        for(int row = 1; row <= ROWS; ++row){
            for(int col = 1; col <= COLS; ++col){
                if(grid[row - 1][col - 1] == 0 && !can[row][col]){
                    return false;
                }
            }
        }
        
        return true;
    }
};