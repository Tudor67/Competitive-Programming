class Solution {
private:
    void bfs(const int& START_ROW, const int& START_COL, const int& CC_ID, vector<vector<int>>& cc){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = cc.size();
        const int COLS = cc[0].size();

        queue<pair<int, int>> q;
        q.push({START_ROW, START_COL});
        cc[START_ROW][START_COL] = CC_ID;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   cc[nextRow][nextCol] == 0){
                    q.push({nextRow, nextCol});
                    cc[nextRow][nextCol] = CC_ID;
                }
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        vector<vector<int>> cc(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(board[row][col] == 'X'){
                    cc[row][col] = -1;
                }else{
                    cc[row][col] = 0;
                }
            }
        }
        
        int ccID = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(cc[row][col] == 0){
                    ++ccID;
                    bfs(row, col, ccID, cc);
                }
            }
        }
        
        vector<bool> isValid(ccID + 2, true);
        for(int row = 0; row < ROWS; ++row){
            isValid[cc[row][0] + 1] = false;
            isValid[cc[row][COLS - 1] + 1] = false;
        }
        
        for(int col = 0; col < COLS; ++col){
            isValid[cc[0][col] + 1] = false;
            isValid[cc[ROWS - 1][col] + 1] = false;
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(isValid[cc[row][col] + 1]){
                    board[row][col] = 'X';
                }
            }
        }
    }
};