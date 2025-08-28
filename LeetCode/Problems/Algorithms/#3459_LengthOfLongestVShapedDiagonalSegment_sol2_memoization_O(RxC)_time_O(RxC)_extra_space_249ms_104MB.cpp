class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    static const int MAX_ROWS = 500;
    static const int MAX_COLS = 500;
    static const int MAX_DIRECTIONS = 4;
    static const int MAX_ROTATIONS = 1;

    int computeMaxVLen(vector<vector<int>>& grid, int row, int col, int dirIdx, bool wasRotated, int targetVal,
                       int memo[MAX_ROWS][MAX_COLS][MAX_DIRECTIONS][MAX_ROTATIONS + 1]){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        if(!(0 <= row && row < ROWS && 0 <= col && col < COLS)){
            return 0;
        }

        if(grid[row][col] != targetVal){
            return 0;
        }

        if(memo[row][col][dirIdx][wasRotated] != -1){
            return memo[row][col][dirIdx][wasRotated];
        }

        int maxVLen = 1 + computeMaxVLen(grid,
                                         row + DIRECTIONS[dirIdx].first,
                                         col + DIRECTIONS[dirIdx].second,
                                         dirIdx, wasRotated, 2 - targetVal, memo);
        if(!wasRotated){
            maxVLen = max(maxVLen, 1 + computeMaxVLen(grid,
                                                      row + DIRECTIONS[(dirIdx + 1) % DIRECTIONS.size()].first,
                                                      col + DIRECTIONS[(dirIdx + 1) % DIRECTIONS.size()].second,
                                                      (dirIdx + 1) % DIRECTIONS.size(), true, 2 - targetVal, memo));
        }

        memo[row][col][dirIdx][wasRotated] = maxVLen;
        return maxVLen;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int memo[MAX_ROWS][MAX_COLS][MAX_DIRECTIONS][MAX_ROTATIONS + 1];
        for(int row = 0; row < MAX_ROWS; ++row){
            for(int col = 0; col < MAX_COLS; ++col){
                for(int dir = 0; dir < MAX_DIRECTIONS; ++dir){
                    for(int r = 0; r <= MAX_ROTATIONS; ++r){
                        memo[row][col][dir][r] = -1;
                    }
                }
            }
        }

        int maxVLen = 0;
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                if(grid[startRow][startCol] == 1){
                    for(int dirIdx = 0; dirIdx < (int)DIRECTIONS.size(); ++dirIdx){
                        int currMaxVLen = 1 + computeMaxVLen(grid,
                                                             startRow + DIRECTIONS[dirIdx].first,
                                                             startCol + DIRECTIONS[dirIdx].second,
                                                             dirIdx, false, 2, memo);
                        maxVLen = max(maxVLen, currMaxVLen);
                    }
                }
            }
        }

        return maxVLen;
    }
};