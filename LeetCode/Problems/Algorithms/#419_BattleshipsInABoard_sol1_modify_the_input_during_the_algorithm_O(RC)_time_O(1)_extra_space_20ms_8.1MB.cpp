class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        const char X = 'X';
        const char Y = 'Y';
        
        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(board[row][col] == X){
                    board[row][col] = Y;
                    bool isStart = true;
                    if(row - 1 >= 0 && board[row - 1][col] == Y){
                        isStart = false;
                    }
                    if(col - 1 >= 0 && board[row][col - 1] == Y){
                        isStart = false;
                    }
                    if(isStart){
                        res += 1;
                    }
                }
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(board[row][col] == Y){
                    board[row][col] = X;
                }
            }
        }
        
        return res;
    }
};