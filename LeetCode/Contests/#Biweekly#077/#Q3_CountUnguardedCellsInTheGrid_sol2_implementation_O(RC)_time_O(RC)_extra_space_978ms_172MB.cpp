class Solution {
public:
    int countUnguarded(int ROWS, int COLS, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        const int EMPTY = 0;
        const int GUARD = 1;
        const int WALL = 2;
        
        vector<vector<int>> grid(ROWS, vector<int>(COLS, EMPTY));
        vector<vector<bool>> ok(ROWS, vector<bool>(COLS, false));
        
        for(const vector<int>& POS: guards){
            int row = POS[0];
            int col = POS[1];
            grid[row][col] = GUARD;
            ok[row][col] = true;
        }
        
        for(const vector<int>& POS: walls){
            int row = POS[0];
            int col = POS[1];
            grid[row][col] = WALL;
            ok[row][col] = true;
        }
        
        const vector<tuple<int, int, int>> COL_DIRECTIONS = {{0, COLS, 1}, {COLS - 1, -1, -1}};
        for(int row = 0; row < ROWS; ++row){
            for(const tuple<int, int, int>& T: COL_DIRECTIONS){
                const int COL_START = get<0>(T);
                const int COL_END = get<1>(T);
                const int COL_DIRECTION = get<2>(T);
                int prevVal = 0;
                for(int col = COL_START; col != COL_END; col += COL_DIRECTION){
                    if(grid[row][col] == GUARD){
                        prevVal = GUARD;
                    }else if(grid[row][col] == WALL){
                        prevVal = WALL;
                    }else{
                        if(prevVal == GUARD){
                            ok[row][col] = true;
                        }
                    }
                }
            }
        }
        
        const vector<tuple<int, int, int>> ROW_DIRECTIONS = {{0, ROWS, 1}, {ROWS - 1, -1, -1}};
        for(int col = 0; col < COLS; ++col){
            for(const tuple<int, int, int>& T: ROW_DIRECTIONS){
                const int ROW_START = get<0>(T);
                const int ROW_END = get<1>(T);
                const int ROW_DIRECTION = get<2>(T);
                int prevVal = 0;
                for(int row = ROW_START; row != ROW_END; row += ROW_DIRECTION){
                    if(grid[row][col] == GUARD){
                        prevVal = GUARD;
                    }else if(grid[row][col] == WALL){
                        prevVal = WALL;
                    }else{
                        if(prevVal == GUARD){
                            ok[row][col] = true;
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(!ok[row][col]){
                    res += 1;
                }
            }
        }
        
        return res;
    }
};