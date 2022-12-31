class Solution {
private:
    enum Cell { OBSTACLE = -1, EMPTY = 0, START = 1, END = 2 };
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    int getIndex(int row, int col, const int& COLS){
        return row * COLS + col;
    }

    int solve(int row, int col, int visMask, vector<vector<int>>& grid, unordered_map<int, int>& memo){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        visMask |= (1 << getIndex(row, col, COLS));
        int state = (getIndex(row, col, COLS) << 20) | visMask;

        if(memo.count(state)){
            // stop
        }else if(grid[row][col] == Cell::END){
            memo[state] = (__builtin_popcount((unsigned int)visMask) == ROWS * COLS);
        }else{
            int validPaths = 0;
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int nextCellIndex = getIndex(nextRow, nextCol, COLS);
                    if(((visMask >> nextCellIndex) & 1) == 0){
                        validPaths += solve(nextRow, nextCol, visMask, grid, memo);
                    }
                }
            }
            memo[state] = validPaths;
        }
        return memo[state];
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int startRow = -1;
        int startCol = -1;
        int visMask = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == Cell::START){
                    startRow = row;
                    startCol = col;
                }
                if(grid[row][col] == Cell::OBSTACLE){
                    visMask |= (1 << getIndex(row, col, COLS));
                }
            }
        }

        unordered_map<int, int> memo;
        return solve(startRow, startCol, visMask, grid, memo);
    }
};