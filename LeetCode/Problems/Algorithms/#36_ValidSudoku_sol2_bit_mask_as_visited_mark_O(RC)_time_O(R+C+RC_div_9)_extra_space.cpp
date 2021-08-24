class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        const int BOX_ROWS = 3;
        const int BOX_COLS = 3;
        
        vector<int> rowVisMask(ROWS, 0);
        vector<int> colVisMask(COLS, 0);
        vector<int> boxVisMask((ROWS * COLS) / (BOX_ROWS * BOX_COLS), 0);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(isdigit(board[row][col])){
                    int digit = board[row][col] - '0';
                    int boxIdx = (row / BOX_ROWS) * BOX_COLS + (col / BOX_COLS);
                    if((rowVisMask[row] >> digit) & 1){
                        return false;
                    }
                    if((colVisMask[col] >> digit) & 1){
                        return false;
                    }
                    if((boxVisMask[boxIdx] >> digit) & 1){
                        return false;
                    }
                    rowVisMask[row] |= (1 << digit);
                    colVisMask[col] |= (1 << digit);
                    boxVisMask[boxIdx] |= (1 << digit);
                }
            }
        }
        
        return true;
    }
};