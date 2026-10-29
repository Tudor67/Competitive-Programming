class Solution {
public:
    vector<string> createGrid(int ROWS, int COLS) {
        const char FREE_CELL = '.';
        const char OBSTACLE_CELL = '#';

        vector<string> grid(ROWS, string(COLS, OBSTACLE_CELL));
        for(int col = 0; col < COLS; ++col){
            grid[0][col] = FREE_CELL;
        }

        for(int row = 0; row < ROWS; ++row){
            grid[row][COLS - 1] = FREE_CELL;
        }

        return grid;
    }
};