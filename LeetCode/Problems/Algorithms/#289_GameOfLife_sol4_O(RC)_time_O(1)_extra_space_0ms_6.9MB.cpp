class Solution {
private:
    const int SHIFT = 10;
    
    int countInitialLiveNeighbors(vector<vector<int>>& board, int row, int col){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1},
                                                          {0, -1}, {0, 1},
                                                          {1, -1}, {1, 0}, {1, 1}};
        const int ROWS = board.size();
        const int COLS = board[0].size();
        int initialLiveNeighbors = 0;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                initialLiveNeighbors += (board[nextRow][nextCol] % SHIFT);
            }
        }
        return initialLiveNeighbors;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int initialLiveNeighbors = countInitialLiveNeighbors(board, row, col);
                if(initialLiveNeighbors == 3 || (initialLiveNeighbors == 2 && board[row][col] == 1)){
                    board[row][col] += SHIFT;
                }
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(board[row][col] >= SHIFT){
                    board[row][col] = 1;
                }else{
                    board[row][col] = 0;
                }
            }
        }
    }
};