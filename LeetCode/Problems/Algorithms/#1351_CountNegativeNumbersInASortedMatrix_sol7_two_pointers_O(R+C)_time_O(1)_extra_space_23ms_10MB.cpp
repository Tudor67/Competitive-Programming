class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int res = 0;
        int row = 0;
        int col = COLS - 1;
        while(row < ROWS && 0 <= col){
            if(grid[row][col] < 0){
                res += (ROWS - row);
                col -= 1;
            }else{
                row += 1;
            }
        }

        return res;
    }
};