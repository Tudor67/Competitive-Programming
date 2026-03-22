class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int res = 0;
        vector<int> xColCount(COLS);
        vector<int> yColCount(COLS);

        for(int row = 0; row < ROWS; ++row){
            int xTotalCount = 0;
            int yTotalCount = 0;
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 'X'){
                    xColCount[col] += 1;
                }else if(grid[row][col] == 'Y'){
                    yColCount[col] += 1;
                }
                xTotalCount += xColCount[col];
                yTotalCount += yColCount[col];
                if(xTotalCount == yTotalCount && xTotalCount > 0){
                    res += 1;
                }
            }
        }

        return res;
    }
};