class Solution {
private:
    int getIdx(int row, int col, const int& COLS){
        return row * COLS + col;
    }
    
    int solve(int row, int col, int emptyCellsMask, vector<vector<int>>& grid){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int totalWalks = 0;
        if(grid[row][col] == 2){
            if(emptyCellsMask == 0){
                totalWalks = 1;
            }
        }else{
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                int nextIdx = getIdx(nextRow, nextCol, COLS);
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && grid[nextRow][nextCol] != -1){
                    if(((emptyCellsMask >> nextIdx) & 1) || grid[nextRow][nextCol] == 2){
                        int nextEmptyCellsMask = emptyCellsMask - (int)(grid[nextRow][nextCol] != 2) * (1 << nextIdx);
                        totalWalks += solve(nextRow, nextCol, nextEmptyCellsMask, grid);
                    }
                }
            }
        }
        return totalWalks;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int startRow = 0;
        int startCol = 0;
        int emptyCellsMask = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    startRow = row;
                    startCol = col;
                }else if(grid[row][col] == 0){
                    emptyCellsMask |= (1 << getIdx(row, col, COLS));
                }
            }
        }
        
        return solve(startRow, startCol, emptyCellsMask, grid);
    }
};