class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int negNumsCount = 0;
        for(int row = 0, col = COLS - 1; row < ROWS; ++row){
            while(col >= 0 && grid[row][col] < 0){
                col -= 1;
            }
            negNumsCount += (COLS - 1 - col);
        }

        return negNumsCount;
    }
};