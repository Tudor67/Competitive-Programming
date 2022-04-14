class Solution {
private:
    int getInitialValue(int transitionID){
        return (transitionID % 2);
    }
    
    int getFinalValue(int transitionID){
        if(transitionID == 0 || transitionID == 3){
            return 0;
        }
        return 1;
    }
    
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
                initialLiveNeighbors += getInitialValue(board[nextRow][nextCol]);
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
                if(getInitialValue(board[row][col]) == 1){
                    if(initialLiveNeighbors <= 1 || initialLiveNeighbors >= 4){
                        // 3: 1 -> 0
                        board[row][col] = 3;
                    }else{
                        // 1: 1 -> 1
                    }
                }else{
                    if(initialLiveNeighbors == 3){
                        // 2: 0 -> 1
                        board[row][col] = 2;
                    }else{
                        // 0: 0 -> 0
                    }
                }
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                board[row][col] = getFinalValue(board[row][col]);
            }
        }
    }
};

/*
Transitions:
TransitionID: InitialValue -> FinalValue
0: 0 -> 0
1: 1 -> 1
2: 0 -> 1
3: 1 -> 0
*/