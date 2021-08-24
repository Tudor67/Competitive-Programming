class Solution {
private:
    void back(int row, int col, const int& N, vector<vector<char>>& board,
              vector<int>& rowVisMask, vector<int>& colVisMask, vector<int>& boxVisMask, bool& found){
        if(found){
            // stop
        }else if(row == N){
            found = true;
        }else if(col == N){
            back(row + 1, 0, N, board, rowVisMask, colVisMask, boxVisMask, found);
        }else if(isdigit(board[row][col])){
            back(row, col + 1, N, board, rowVisMask, colVisMask, boxVisMask, found);
        }else{
            for(int digit = 1; !found && digit <= 9; ++digit){
                int digitMask = (1 << digit);
                int boxIdx = (row / 3) * 3 + (col / 3);
                if(!(rowVisMask[row] & digitMask) && !(colVisMask[col] & digitMask) && !(boxVisMask[boxIdx] & digitMask)){
                    rowVisMask[row] ^= digitMask;
                    colVisMask[col] ^= digitMask;
                    boxVisMask[boxIdx] ^= digitMask;
                    board[row][col] = char('0' + digit);
                    back(row, col + 1, N, board, rowVisMask, colVisMask, boxVisMask, found);
                    if(!found){
                        board[row][col] = '.';
                    }
                    rowVisMask[row] ^= digitMask;
                    colVisMask[col] ^= digitMask;
                    boxVisMask[boxIdx] ^= digitMask;
                }
            }
        }
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        const int N = board.size();
        
        vector<int> rowVisMask(N, 0);
        vector<int> colVisMask(N, 0);
        vector<int> boxVisMask(N, 0);
        
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(isdigit(board[row][col])){
                    int digit = board[row][col] - '0';
                    int boxIdx = (row / 3) * 3 + (col / 3);
                    int digitMask = (1 << digit);
                    rowVisMask[row] |= digitMask;
                    colVisMask[col] |= digitMask;
                    boxVisMask[boxIdx] |= digitMask;
                }
            }
        }
        
        bool found = false;
        back(0, 0, N, board, rowVisMask, colVisMask, boxVisMask, found);
    }
};