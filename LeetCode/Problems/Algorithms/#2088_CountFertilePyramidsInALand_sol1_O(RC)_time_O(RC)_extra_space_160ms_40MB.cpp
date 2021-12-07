class Solution {
private:
    int countPyramidalPlots(vector<vector<int>> h){
        const int ROWS = h.size();
        const int COLS = h[0].size();
        
        for(int col = 0; col < COLS; ++col){
            for(int row = 1; row < ROWS; ++row){
                if(h[row][col] == 1){
                    h[row][col] += h[row - 1][col];
                }
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                h[row][col] = min(h[row][col], 1 + min(COLS - 1 - col, col));
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                h[row][col] = min(h[row][col - 1] + 1, h[row][col]);
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = COLS - 2; col >= 0; --col){
                h[row][col] = min(h[row][col], 1 + h[row][col + 1]);
            }
        }
        
        int pyramids = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(h[row][col] >= 2){
                    pyramids += (h[row][col] - 1);
                }
            }
        }
        
        return pyramids;
    }
    
public:
    int countPyramids(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int pyramids = 0;
        
        for(int row = 0; row < ROWS / 2; ++row){
            swap(grid[row], grid[ROWS - 1 - row]);
        }
        
        // count inverse pyramids
        pyramids += countPyramidalPlots(grid);
        
        for(int row = 0; row < ROWS / 2; ++row){
            swap(grid[row], grid[ROWS - 1 - row]);
        }
        
        // count pyramids
        pyramids += countPyramidalPlots(grid);
        
        return pyramids;
    }
};