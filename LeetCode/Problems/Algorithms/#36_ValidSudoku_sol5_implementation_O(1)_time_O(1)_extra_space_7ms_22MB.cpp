class Solution {
private:
    bool containsValidRows(vector<vector<char>>& board){
        for(int row = 0; row < 9; ++row){
            vector<bool> vis(10, false);
            for(int col = 0; col < 9; ++col){
                if(isdigit(board[row][col])){
                    if(vis[board[row][col] - '0']){
                        return false;
                    }
                    vis[board[row][col] - '0'] = true;
                }
            }
        }
        return true;
    }

    bool containsValidCols(vector<vector<char>>& board){
        for(int col = 0; col < 9; ++col){
            vector<bool> vis(10, false);
            for(int row = 0; row < 9; ++row){
                if(isdigit(board[row][col])){
                    if(vis[board[row][col] - '0']){
                        return false;
                    }
                    vis[board[row][col] - '0'] = true;
                }
            }
        }
        return true;
    }

    bool containsValidSubBoxes(vector<vector<char>>& board){
        for(int startRow = 0; startRow < 9; startRow += 3){
            for(int startCol = 0; startCol < 9; startCol += 3){
                vector<bool> vis(10, false);
                for(int row = startRow; row < startRow + 3; ++row){
                    for(int col = startCol; col < startCol + 3; ++col){
                        if(isdigit(board[row][col])){
                            if(vis[board[row][col] - '0']){
                                return false;
                            }
                            vis[board[row][col] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return containsValidRows(board) &&
               containsValidCols(board) &&
               containsValidSubBoxes(board);
    }
};