class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        const char X = 'X';
        
        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(board[row][col] == X){
                    bool isEnd = true;
                    if(row - 1 >= 0 && board[row - 1][col] == X){
                        isEnd = false;
                    }
                    if(col + 1 < COLS && board[row][col + 1] == X){
                        isEnd = false;
                    }
                    if(isEnd){
                        res += 1;
                    }
                }
            }
        }
        
        return res;
    }
};