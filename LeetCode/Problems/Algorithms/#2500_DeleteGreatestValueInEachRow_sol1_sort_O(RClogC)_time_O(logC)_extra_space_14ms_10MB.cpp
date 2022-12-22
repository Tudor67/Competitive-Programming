class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        for(int row = 0; row < ROWS; ++row){
            sort(grid[row].rbegin(), grid[row].rend());
        }

        int res = 0;
        for(int col = 0; col < COLS; ++col){
            int maxVal = grid[0][col];
            for(int row = 0; row < ROWS; ++row){
                maxVal = max(maxVal, grid[row][col]);
            }
            res += maxVal;
        }

        return res;
    }
};