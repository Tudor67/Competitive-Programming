class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        const int SUB_BOX_ROWS = 3;
        const int SUB_BOX_COLS = 3;
        const int SUB_BOXES = ((ROWS - 1) / SUB_BOX_ROWS + 1) *
                              ((COLS - 1) / SUB_BOX_COLS + 1);
        
        vector<int> rowVisMask(ROWS);
        vector<int> colVisMask(COLS);
        vector<int> subBoxVisMask(SUB_BOXES);
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(isdigit(board[row][col])){
                    int digit = board[row][col] - '0';
                    int subBoxRow = row / SUB_BOX_ROWS;
                    int subBoxCol = col / SUB_BOX_COLS;
                    int subBoxIndex = subBoxRow * ((COLS - 1) / SUB_BOX_COLS + 1) + subBoxCol;
                    
                    if(((rowVisMask[row] >> digit) & 1) ||
                       ((colVisMask[col] >> digit) & 1) ||
                       ((subBoxVisMask[subBoxIndex] >> digit) & 1)){
                        return false;
                    }

                    rowVisMask[row] |= (1 << digit);
                    colVisMask[col] |= (1 << digit);
                    subBoxVisMask[subBoxIndex] |= (1 << digit);
                }
            }
        }
        
        return true;
    }
};