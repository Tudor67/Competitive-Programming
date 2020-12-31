class Solution {
private:
    int getState(int cell, int liveNeighbors){
        int state = INT_MIN;
        if(cell == 1){
            if(liveNeighbors == 2 || liveNeighbors == 3){
                state = 1;
            }else{
                state = 2;
            }
        }else{
            if(liveNeighbors == 3){
                state = -1;
            }else{
                state = 0;
            }
        }
        return state;
    }
    
    int getInitialValue(int state){
        if(state <= 0){
            return 0;
        }
        return 1;
    }
    
    int getFinalValue(int state){
        if(state == -1 || state == 1){
            return 1;
        }
        return 0;
    }
    
    bool isInside(int row, int col, vector<vector<int>>& board){
        return (0 <= row && row < board.size() && 0 <= col && col < board[0].size());
    }
    
    int countLiveNeighbors(int row, int col, vector<vector<int>>& board){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1},
                                                          {0, -1}, {0, 1},
                                                          {1, -1}, {1, 0}, {1, 1}};
        int liveNeighbors = 0;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(isInside(nextRow, nextCol, board)){
                liveNeighbors += (getInitialValue(board[nextRow][nextCol]) == 1);
            }
        }
        return liveNeighbors;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int row = 0; row < board.size(); ++row){
            for(int col = 0; col < board[0].size(); ++col){
                int liveNeighbors = countLiveNeighbors(row, col, board);
                board[row][col] = getState(getInitialValue(board[row][col]), liveNeighbors);
            }
        }
        for(int row = 0; row < board.size(); ++row){
            for(int col = 0; col < board[0].size(); ++col){
                board[row][col] = getFinalValue(board[row][col]);
            }
        }
    }
};