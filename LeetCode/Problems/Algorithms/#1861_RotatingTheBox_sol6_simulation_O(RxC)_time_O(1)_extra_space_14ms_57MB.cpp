class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        const int ROWS = boxGrid[0].size();
        const int COLS = boxGrid.size();
        const char STONE = '#';
        const char OBSTACLE = '*';
        const char EMPTY = '.';

        // rotate the grid 90 degrees clockwise
        vector<vector<char>> res(ROWS, vector<char>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[row][col] = boxGrid[col][row];
            }
        }

        for(int row = 0; row < ROWS; ++row){
            reverse(res[row].begin(), res[row].end());
        }

        // simulate the falling process
        for(int col = 0; col < COLS; ++col){
            int lastEmptyRow = ROWS - 1;
            for(int row = ROWS - 1; row >= 0; --row){
                if(res[row][col] == STONE){
                    res[row][col] = EMPTY;
                    res[lastEmptyRow][col] = STONE;
                    --lastEmptyRow;
                }else if(res[row][col] == OBSTACLE){
                    lastEmptyRow = row - 1;
                }
            }
        }

        return res;
    }
};