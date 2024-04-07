class Solution {
private:
    void search(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& vis,
                int i, string& word, bool& found){
        const int ROWS = board.size();
        const int COLS = board[0].size();
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        if(found){
            // stop
        }else if(i == (int)word.length()){
            found = true;
        }else if(0 <= row && row < ROWS && 0 <= col && col < COLS &&
                 !vis[row][col] && board[row][col] == word[i]){
            vis[row][col] = true;
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                search(nextRow, nextCol, board, vis, i + 1, word, found);
            }
            vis[row][col] = false;
        }
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        bool found = false;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                search(row, col, board, vis, 0, word, found);
            }
        }

        return found;
    }
};