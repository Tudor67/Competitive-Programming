class Solution {
private:
    void back(int row, int col, int emptyCells, vector<vector<int>>& grid, int& totalWalks){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int cellVal = grid[row][col];
        grid[row][col] = -1;
        if(cellVal == 2){
            if(emptyCells == 0){
                ++totalWalks;
            }
        }else{
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && grid[nextRow][nextCol] != -1){
                    back(nextRow, nextCol, emptyCells - (int)(grid[nextRow][nextCol] != 2), grid, totalWalks);
                }
            }
        }
        grid[row][col] = cellVal;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int startRow = 0;
        int startCol = 0;
        int emptyCells = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    startRow = row;
                    startCol = col;
                }else if(grid[row][col] == 0){
                    ++emptyCells;
                }
            }
        }
        
        int totalWalks = 0;
        back(startRow, startCol, emptyCells, grid, totalWalks);
        
        return totalWalks;
    }
};