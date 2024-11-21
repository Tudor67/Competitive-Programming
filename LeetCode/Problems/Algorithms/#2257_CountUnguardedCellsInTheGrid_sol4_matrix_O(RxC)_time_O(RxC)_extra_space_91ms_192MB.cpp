class Solution {
public:
    int countUnguarded(int ROWS, int COLS, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        enum CellType { WALL, GUARDED, FREE };

        vector<vector<int>> inGrid(ROWS, vector<int>(COLS, CellType::FREE));
        for(const vector<int>& POS: guards){
            inGrid[POS[0]][POS[1]] = CellType::GUARDED;
        }

        for(const vector<int>& POS: walls){
            inGrid[POS[0]][POS[1]] = CellType::WALL;
        }

        vector<vector<int>> currGrid = inGrid;
        for(int row = 0; row < ROWS; ++row){
            int prevSpecialCell = inGrid[row][0];
            for(int col = 1; col < COLS; ++col){
                if(prevSpecialCell == CellType::GUARDED && currGrid[row][col] == CellType::FREE){
                    currGrid[row][col] = CellType::GUARDED;
                }
                if(inGrid[row][col] != CellType::FREE){
                    prevSpecialCell = inGrid[row][col];
                }
            }

            prevSpecialCell = inGrid[row][COLS - 1];
            for(int col = COLS - 2; col >= 0; --col){
                if(prevSpecialCell == CellType::GUARDED && currGrid[row][col] == CellType::FREE){
                    currGrid[row][col] = CellType::GUARDED;
                }
                if(inGrid[row][col] != CellType::FREE){
                    prevSpecialCell = inGrid[row][col];
                }
            }
        }

        for(int col = 0; col < COLS; ++col){
            int prevSpecialCell = inGrid[0][col];
            for(int row = 1; row < ROWS; ++row){
                if(prevSpecialCell == CellType::GUARDED && currGrid[row][col] == CellType::FREE){
                    currGrid[row][col] = CellType::GUARDED;
                }
                if(inGrid[row][col] != CellType::FREE){
                    prevSpecialCell = inGrid[row][col];
                }
            }

            prevSpecialCell = inGrid[ROWS - 1][col];
            for(int row = ROWS - 2; row >= 0; --row){
                if(prevSpecialCell == CellType::GUARDED && currGrid[row][col] == CellType::FREE){
                    currGrid[row][col] = CellType::GUARDED;
                }
                if(inGrid[row][col] != CellType::FREE){
                    prevSpecialCell = inGrid[row][col];
                }
            }
        }

        int freeCells = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(currGrid[row][col] == CellType::FREE){
                    freeCells += 1;
                }
            }
        }

        return freeCells;
    }
};