class Solution {
private:
    int getBoxIndex(int row, int col){
        return 3 * (row / 3) + (col / 3);
    }

    void solve(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& visAtRow,
               vector<vector<bool>>& visAtCol, vector<vector<bool>>& visAtBox, bool& found){
        if(col == 9){
            solve(board, row + 1, 0, visAtRow, visAtCol, visAtBox, found);
        }else if(row == 9){
            found = true;
        }else if(isdigit(board[row][col])){
            solve(board, row, col + 1, visAtRow, visAtCol, visAtBox, found);
        }else{
            for(int digit = 1; digit <= 9 && !found; ++digit){
                if(!visAtRow[row][digit] && !visAtCol[col][digit] && !visAtBox[getBoxIndex(row, col)][digit]){
                    board[row][col] = char(digit + '0');
                    visAtRow[row][digit] = true;
                    visAtCol[col][digit] = true;
                    visAtBox[getBoxIndex(row, col)][digit] = true;
                    solve(board, row, col + 1, visAtRow, visAtCol, visAtBox, found);
                    if(!found){
                        board[row][col] = '.';
                        visAtRow[row][digit] = false;
                        visAtCol[col][digit] = false;
                        visAtBox[getBoxIndex(row, col)][digit] = false;
                    }
                }
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> visAtRow(9, vector<bool>(10, false));
        vector<vector<bool>> visAtCol(9, vector<bool>(10, false));
        vector<vector<bool>> visAtBox(9, vector<bool>(10, false));

        for(int row = 0; row < 9; ++row){
            for(int col = 0; col < 9; ++col){
                if(isdigit(board[row][col])){
                    int digit = board[row][col] - '0';
                    visAtRow[row][digit] = true;
                    visAtCol[col][digit] = true;
                    visAtBox[getBoxIndex(row, col)][digit] = true;
                }
            }
        }

        bool found = false;
        solve(board, 0, 0, visAtRow, visAtCol, visAtBox, found);
    }
};