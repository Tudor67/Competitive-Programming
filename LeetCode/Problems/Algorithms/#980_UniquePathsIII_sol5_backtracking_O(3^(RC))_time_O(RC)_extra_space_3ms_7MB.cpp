class Solution {
private:
    enum Cell { OBSTACLE = -1, EMPTY = 0, START = 1, END = 2 };
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void back(int row, int col, int cellsToVisit, vector<vector<int>>& grid, int& validPathsCount){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        if(grid[row][col] == Cell::END){
            if(cellsToVisit == 1){
                validPathsCount += 1;
            }
        }else{
            int originalCell = grid[row][col];
            grid[row][col] = Cell::OBSTACLE;
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(grid[nextRow][nextCol] != Cell::OBSTACLE){
                        back(nextRow, nextCol, cellsToVisit - 1, grid, validPathsCount);
                    }
                }
            }
            grid[row][col] = originalCell;
        }
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int startRow = -1;
        int startCol = -1;
        int validCells = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == Cell::START){
                    startRow = row;
                    startCol = col;
                }
                if(grid[row][col] != Cell::OBSTACLE){
                    validCells += 1;
                }
            }
        }

        vector<vector<int>> gridCopy = grid;
        int validPathsCount = 0;
        back(startRow, startCol, validCells, gridCopy, validPathsCount);

        return validPathsCount;
    }
};