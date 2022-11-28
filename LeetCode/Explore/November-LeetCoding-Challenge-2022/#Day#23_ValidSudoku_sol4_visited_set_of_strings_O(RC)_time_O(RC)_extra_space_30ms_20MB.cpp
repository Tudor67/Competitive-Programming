class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        unordered_set<string> vis;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(isdigit(board[row][col])){
                    int digit = board[row][col] - '0';
                    if(!vis.insert(to_string(digit) + "r" + to_string(row)).second){
                        return false;
                    }
                    if(!vis.insert(to_string(digit) + "c" + to_string(col)).second){
                        return false;
                    }
                    if(!vis.insert(to_string(digit) + "b" + to_string(row / 3) + "-" + to_string(col / 3)).second){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};