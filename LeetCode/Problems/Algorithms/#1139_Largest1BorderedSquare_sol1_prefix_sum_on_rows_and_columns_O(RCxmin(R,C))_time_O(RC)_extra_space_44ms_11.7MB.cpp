class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<int>> rowSum(ROWS, vector<int>(COLS));
        vector<vector<int>> colSum(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                rowSum[row][col] += grid[row][col];
                if(col - 1 >= 0){
                    rowSum[row][col] += rowSum[row][col - 1];
                }
                colSum[row][col] += grid[row][col];
                if(row - 1 >= 0){
                    colSum[row][col] += colSum[row - 1][col];
                }
            }
        }
        
        int maxSideOfSquare = 0;
        for(int row1 = 0; row1 < ROWS; ++row1){
            for(int col1 = 0; col1 < COLS; ++col1){
                for(int side = maxSideOfSquare + 1; row1 + side - 1 < ROWS && col1 + side - 1 < COLS; ++side){
                    int row2 = row1 + side - 1;
                    int col2 = col1 + side - 1;
                    int rowSum1 = rowSum[row1][col2] - (col1 - 1 >= 0 ? rowSum[row1][col1 - 1] : 0);
                    int rowSum2 = rowSum[row2][col2] - (col1 - 1 >= 0 ? rowSum[row2][col1 - 1] : 0);
                    int colSum1 = colSum[row2][col1] - (row1 - 1 >= 0 ? colSum[row1 - 1][col1] : 0);
                    int colSum2 = colSum[row2][col2] - (row1 - 1 >= 0 ? colSum[row1 - 1][col2] : 0);
                    if(rowSum1 == side && rowSum2 == side && colSum1 == side && colSum2 == side){
                        maxSideOfSquare = max(maxSideOfSquare, side);
                    }
                    if(rowSum1 != side || colSum1 != side){
                        break;
                    }
                }
            }
        }
        
        return maxSideOfSquare * maxSideOfSquare;
    }
};