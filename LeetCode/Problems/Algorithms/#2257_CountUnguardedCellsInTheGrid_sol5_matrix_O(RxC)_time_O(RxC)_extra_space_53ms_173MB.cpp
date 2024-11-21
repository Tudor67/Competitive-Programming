class Solution {
public:
    int countUnguarded(int ROWS, int COLS, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        enum CellType { GUARD = 4, FREE = 5, WALL = 6 };

        vector<vector<int>> grid(ROWS, vector<int>(COLS, CellType::FREE));
        for(const vector<int>& POS: guards){
            grid[POS[0]][POS[1]] = CellType::GUARD;
        }

        for(const vector<int>& POS: walls){
            grid[POS[0]][POS[1]] = CellType::WALL;
        }

        auto isInside = [&](int row, int col){
            return (0 <= row && row < ROWS && 0 <= col && col < COLS);
        };

        for(const vector<int>& POS: guards){
            int startRow = POS[0];
            int startCol = POS[1];
            for(int dirID = 0; dirID < (int)DIRECTIONS.size(); ++dirID){
                int row = startRow + DIRECTIONS[dirID].first;
                int col = startCol + DIRECTIONS[dirID].second;
                while(isInside(row, col) &&
                      grid[row][col] != CellType::GUARD &&
                      grid[row][col] != CellType::WALL){
                    grid[row][col] = dirID;
                    row += DIRECTIONS[dirID].first;
                    col += DIRECTIONS[dirID].second;
                }
            }
        }

        int freeCells = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == CellType::FREE){
                    freeCells += 1;
                }
            }
        }

        return freeCells;
    }
};