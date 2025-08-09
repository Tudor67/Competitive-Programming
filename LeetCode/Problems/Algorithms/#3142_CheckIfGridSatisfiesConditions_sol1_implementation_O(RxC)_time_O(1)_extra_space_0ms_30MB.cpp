class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row + 1 < ROWS && grid[row][col] != grid[row + 1][col]){
                    return false;
                }
                if(col + 1 < COLS && grid[row][col] == grid[row][col + 1]){
                    return false;
                }
            }
        }

        return true;
    }
};