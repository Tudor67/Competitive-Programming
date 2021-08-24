class Solution {
private:
    bool isValidRow(const int& ROW, const vector<vector<char>>& BOARD, const int& ROWS, const int& COLS){
        int visMask = 0;
        for(int col = 0; col < COLS; ++col){
            if(isdigit(BOARD[ROW][col])){
                int cellVal = BOARD[ROW][col] - '0';
                if((visMask >> cellVal) & 1){
                    return false;
                }
                visMask |= (1 << cellVal);
            }
        }
        return true;
    }
    
    bool isValidCol(const int& COL, const vector<vector<char>>& BOARD, const int& ROWS, const int& COLS){
        int visMask = 0;
        for(int row = 0; row < ROWS; ++row){
            if(isdigit(BOARD[row][COL])){
                int cellVal = BOARD[row][COL] - '0';
                if((visMask >> cellVal) & 1){
                    return false;
                }
                visMask |= (1 << cellVal);
            }
        }
        return true;
    }
    
    bool isValidSubGrid(const int& START_ROW, const int& START_COL,
                        const int& SUB_GRID_ROWS, const int& SUB_GRID_COLS,
                        const vector<vector<char>>& BOARD, const int& ROWS, const int& COLS){
        int visMask = 0;
        for(int row = START_ROW; row < min(START_ROW + SUB_GRID_ROWS, ROWS); ++row){
            for(int col = START_COL; col < min(START_COL + SUB_GRID_COLS, COLS); ++col){
                if(isdigit(BOARD[row][col])){
                    int cellVal = BOARD[row][col] - '0';
                    if((visMask >> cellVal) & 1){
                        return false;
                    }
                    visMask |= (1 << cellVal);
                }
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            if(!isValidRow(row, board, ROWS, COLS)){
                return false;
            }
        }
        
        for(int col = 0; col < COLS; ++col){
            if(!isValidCol(col, board, ROWS, COLS)){
                return false;
            }
        }
        
        for(int row = 0; row < ROWS; row += 3){
            for(int col = 0; col < COLS; col += 3){
                if(!isValidSubGrid(row, col, 3, 3, board, ROWS, COLS)){
                    return false;
                }
            }
        }
        
        return true;
    }
};