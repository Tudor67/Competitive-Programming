class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, const char& SPECIAL_CHAR){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        if(!(0 <= row && row < ROWS && 0 <= col && col < COLS && board[row][col] == 'O')){
            return;
        }
        
        board[row][col] = SPECIAL_CHAR;
        
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            dfs(nextRow, nextCol, board, SPECIAL_CHAR);
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        const char SPECIAL_CHAR = '#';
        
        for(int row = 0; row < ROWS; ++row){
            dfs(row, 0, board, SPECIAL_CHAR);
            dfs(row, COLS - 1, board, SPECIAL_CHAR);
        }
        
        for(int col = 0; col < COLS; ++col){
            dfs(0, col, board, SPECIAL_CHAR);
            dfs(ROWS - 1, col, board, SPECIAL_CHAR);
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(board[row][col] == SPECIAL_CHAR){
                    board[row][col] = 'O';
                }else{
                    board[row][col] = 'X';
                }
            }
        }
    }
};