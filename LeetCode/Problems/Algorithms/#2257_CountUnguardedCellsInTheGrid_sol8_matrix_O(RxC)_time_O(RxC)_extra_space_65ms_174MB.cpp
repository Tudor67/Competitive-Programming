class Solution {
public:
    int countUnguarded(int ROWS, int COLS, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        enum CellType { EMPTY, WALL, GUARD, GUARDED };
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        vector<vector<int>> grid(ROWS, vector<int>(COLS, CellType::EMPTY));

        for(vector<int>& cell: guards){
            grid[cell[0]][cell[1]] = CellType::GUARD;
        }

        for(vector<int>& cell: walls){
            grid[cell[0]][cell[1]] = CellType::WALL;
        }

        for(vector<int>& startCell: guards){
            for(auto& [rowDir, colDir]: DIRECTIONS){
                int row = startCell[0] + rowDir;
                int col = startCell[1] + colDir;
                while(0 <= row && row < ROWS && 0 <= col && col < COLS &&
                      grid[row][col] != CellType::WALL && grid[row][col] != CellType::GUARD){
                    grid[row][col] = CellType::GUARDED;
                    row += rowDir;
                    col += colDir;
                }
            }
        }

        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == CellType::EMPTY){
                    res += 1;
                }
            }
        }

        return res;
    }
};