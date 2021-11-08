class Solution {
private:
    void bfs(const int& START_ROW, const int& START_COL, vector<vector<char>>& board, const char& SPECIAL_CHAR){
        if(board[START_ROW][START_COL] != 'O'){
            return;
        }
        
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        queue<pair<int, int>> q;
        q.push({START_ROW, START_COL});
        board[START_ROW][START_COL] = SPECIAL_CHAR;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && board[nextRow][nextCol] == 'O'){
                    q.push({nextRow, nextCol});
                    board[nextRow][nextCol] = SPECIAL_CHAR;
                }
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        const char SPECIAL_CHAR = '#';
        
        for(int row = 0; row < ROWS; ++row){
            bfs(row, 0, board, SPECIAL_CHAR);
            bfs(row, COLS - 1, board, SPECIAL_CHAR);
        }
        
        for(int col = 0; col < COLS; ++col){
            bfs(0, col, board, SPECIAL_CHAR);
            bfs(ROWS - 1, col, board, SPECIAL_CHAR);
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