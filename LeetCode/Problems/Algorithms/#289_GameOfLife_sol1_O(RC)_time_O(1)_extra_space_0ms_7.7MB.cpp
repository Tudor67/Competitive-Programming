class Solution {
private:
    int getInitialValue(int cell){
        if(0 <= cell && cell <= 1){
            return cell;
        }
        return (cell < 0);
    }
    
    int getFinalValue(int cell){
        return (1 <= cell && cell <= 2);
    }
    
    bool isInside(const int& ROW, const int& COL, const int& MAX_ROW, const int& MAX_COL){
        return (0 <= ROW && ROW <= MAX_ROW && 0 <= COL && COL <= MAX_COL);
    }
    
    int getNextValue(const int& ROW, const int& COL, const vector<vector<int>>& BOARD){
        const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        const int MAX_ROW = (int)BOARD.size() - 1;
        const int MAX_COL = (int)BOARD[0].size() - 1;
        
        int liveNeighbors = 0;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = ROW + DIRECTION.first;
            int nextCol = COL + DIRECTION.second;
            if(isInside(nextRow, nextCol, MAX_ROW, MAX_COL)){
                liveNeighbors += getInitialValue(BOARD[nextRow][nextCol]);
            }
        }
        
        int nextValue = BOARD[ROW][COL];
        if(BOARD[ROW][COL] == 0){
            if(liveNeighbors == 3){
                nextValue = 2;
            }
        }else{
            if(liveNeighbors < 2 || liveNeighbors > 3){
                nextValue = -2;
            }
        }
        
        return nextValue;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        // Operation : Code
        // 0 -> 0    :  0
        // 1 -> 1    :  1
        // 0 -> 1    :  2
        // 1 -> 0    : -2
        
        for(int row = 0; row < board.size(); ++row){
            for(int col = 0; col < board[0].size(); ++col){
                board[row][col] = getNextValue(row, col, board);
            }
        }
        
        for(int row = 0; row < board.size(); ++row){
            for(int col = 0; col < board[0].size(); ++col){
                board[row][col] = getFinalValue(board[row][col]);
            }
        }
    }
};