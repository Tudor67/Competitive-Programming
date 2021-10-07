class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int rowsMask = 0;
        for(int row = 0; row < ROWS; ++row){
            if(grid[row][0] == 0){
                rowsMask |= (1 << row);
            }
        }
        
        int colsMask = 0;
        for(int col = 1; col < COLS; ++col){
            int colScore = 0;
            for(int row = 0; row < ROWS; ++row){
                if((rowsMask >> row) & 1){
                    colScore += !grid[row][col];
                }else{
                    colScore += grid[row][col];
                }
            }
            if(colScore < ROWS - colScore){
                colsMask |= (1 << col);
            }
        }
        
        int maxScore = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(((rowsMask >> row) & 1) ^ ((colsMask >> col) & 1)){
                    maxScore += ((!grid[row][col]) << (COLS - 1 - col));
                }else{
                    maxScore += (grid[row][col] << (COLS - 1 - col));
                }
            }
        }
        
        return maxScore;
    }
};