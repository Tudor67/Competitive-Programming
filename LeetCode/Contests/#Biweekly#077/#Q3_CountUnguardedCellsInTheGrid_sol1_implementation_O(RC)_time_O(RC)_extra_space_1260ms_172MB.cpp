class Solution {
public:
    int countUnguarded(int ROWS, int COLS, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
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
        
        for(const vector<int>& POS: guards){
            const int START_ROW = POS[0];
            const int START_COL = POS[1];
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int row = START_ROW + DIRECTION.first;
                int col = START_COL + DIRECTION.second;
                while(0 <= row && row < ROWS && 0 <= col && col < COLS && grid[row][col] == EMPTY){
                    ok[row][col] = true;
                    row += DIRECTION.first;
                    col += DIRECTION.second;
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