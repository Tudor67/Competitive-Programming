class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<int> rowOnes(ROWS);
        vector<int> colOnes(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                rowOnes[row] += grid[row][col];
                colOnes[col] += grid[row][col];
            }
        }

        long long res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col]){
                    res += (rowOnes[row] - 1) * (colOnes[col] - 1);
                }
            }
        }

        return res;
    }
};