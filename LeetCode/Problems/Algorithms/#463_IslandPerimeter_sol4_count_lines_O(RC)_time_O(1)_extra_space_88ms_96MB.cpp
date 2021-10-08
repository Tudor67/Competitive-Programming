class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int hLines = 0;
        for(int col = 0; col < COLS; ++col){
            int prevVal = 0;
            for(int row = 0; row < ROWS; ++row){
                if(prevVal != grid[row][col]){
                    hLines += 1;
                }
                prevVal = grid[row][col];
            }
            hLines += grid[ROWS - 1][col];
        }
        
        int vLines = 0;
        for(int row = 0; row < ROWS; ++row){
            int prevVal = 0;
            for(int col = 0; col < COLS; ++col){
                if(prevVal != grid[row][col]){
                    vLines += 1;
                }
                prevVal = grid[row][col];
            }
            vLines += grid[row][COLS - 1];
        }
        
        return hLines + vLines;
    }
};