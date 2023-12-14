class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<int> rowSum(ROWS);
        vector<int> colSum(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                rowSum[row] += grid[row][col];
                colSum[col] += grid[row][col];
            }
        }

        vector<vector<int>> diff = grid;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                diff[row][col] = rowSum[row] + colSum[col] - (COLS - rowSum[row]) - (ROWS - colSum[col]);
            }
        }

        return diff;
    }
};