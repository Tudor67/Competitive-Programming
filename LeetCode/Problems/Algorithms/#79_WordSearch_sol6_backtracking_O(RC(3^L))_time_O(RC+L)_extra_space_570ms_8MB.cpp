class Solution {
private:
    bool exist(int row, int col, string& word, int index, vector<vector<char>>& board){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        if(index == (int)word.length()){
            return true;
        }
        
        if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
            return false;
        }
        
        if(word[index] != board[row][col]){
            return false;
        }
        
        bool found = false;
        for(int i = 0; i < (int)DIRECTIONS.size() && !found; ++i){
            int nextRow = row + DIRECTIONS[i].first;
            int nextCol = col + DIRECTIONS[i].second;
            
            char initialChar = board[row][col];
            board[row][col] = '#';
            found = found || exist(nextRow, nextCol, word, index + 1, board);
            board[row][col] = initialChar;
        }
        
        return found;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        vector<vector<char>> boardCopy = board;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(exist(row, col, word, 0, boardCopy)){
                    return true;
                }
            }
        }
        
        return false;
    }
};