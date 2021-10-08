class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    vector<int> getCounter(const vector<vector<char>>& BOARD){
        const int ROWS = BOARD.size();
        const int COLS = BOARD[0].size();
        vector<int> count(128, 0);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                count[BOARD[row][col]] += 1;
            }
        }
        return count;
    }
    
    bool exists(int row, int col, int idx, string& WORD, const vector<vector<char>>& BOARD, vector<vector<bool>>& vis){
        const int ROWS = BOARD.size();
        const int COLS = BOARD[0].size();
        if(idx == (int)WORD.length() - 1){
            return true;
        }
        bool found = false;
        vis[row][col] = true;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
               !vis[nextRow][nextCol] && WORD[idx + 1] == BOARD[nextRow][nextCol]){
                if(exists(nextRow, nextCol, idx + 1, WORD, BOARD, vis)){
                    found = true;
                    break;
                }
            }
        }
        vis[row][col] = false;
        return found;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        // sanity check
        if(ROWS * COLS < (int)word.length()){
            return false;
        }
        
        vector<int> boardCharCount = getCounter(board);
        vector<int> wordCharCount = getCounter({vector<char>(word.begin(), word.end())});
        for(int c = 0; c < (int)wordCharCount.size(); ++c){
            if(wordCharCount[c] > boardCharCount[c]){
                return false;
            }
        }
        
        // backtracking
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS + 1, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(word[0] == board[row][col]){
                    if(exists(row, col, 0, word, board, vis)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};