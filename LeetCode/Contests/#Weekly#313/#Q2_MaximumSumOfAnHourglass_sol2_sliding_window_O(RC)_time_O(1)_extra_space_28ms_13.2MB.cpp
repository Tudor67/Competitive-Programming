class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int res = 0;
        for(int row = 1; row + 1 < ROWS; ++row){
            int topSum = grid[row - 1][0] + grid[row - 1][1] + grid[row - 1][2];
            int bottomSum = grid[row + 1][0] + grid[row + 1][1] + grid[row + 1][2];
            for(int col = 1; col + 1 < COLS; ++col){
                res = max(res, topSum + grid[row][col] + bottomSum);
                topSum -= grid[row - 1][col - 1];
                bottomSum -= grid[row + 1][col - 1];
                if(col + 2 < COLS){
                    topSum += grid[row - 1][col + 2];
                    bottomSum += grid[row + 1][col + 2];
                }
            }
        }
        
        return res;
    }
};