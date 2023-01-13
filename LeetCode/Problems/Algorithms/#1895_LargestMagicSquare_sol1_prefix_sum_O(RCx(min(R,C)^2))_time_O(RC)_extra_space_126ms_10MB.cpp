class Solution {
private:
    int getVal(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || col < 0){
            return 0;
        }
        return grid[row][col];
    }
    
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> hPrefSum(ROWS, vector<int>(COLS));
        vector<vector<int>> vPrefSum(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                hPrefSum[row][col] = grid[row][col] + getVal(hPrefSum, row, col - 1);
                vPrefSum[row][col] = grid[row][col] + getVal(vPrefSum, row - 1, col);
            }
        }

        int res = 1;
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                for(int k = res + 1; k <= min(ROWS - startRow, COLS - startCol); ++k){
                    int endRow = startRow + k - 1;
                    int endCol = startCol + k - 1;

                    // check diagonals
                    int diagSum1 = 0;
                    int diagSum2 = 0;
                    for(int i = 0; i < k; ++i){
                        diagSum1 += grid[startRow + i][startCol + i];
                        diagSum2 += grid[startRow + i][endCol - i];
                    }

                    // check rows and cols sum
                    bool isValid = (diagSum1 == diagSum2);
                    int targetSum = diagSum1;
                    for(int row = startRow; row <= endRow; ++row){
                        if(hPrefSum[row][endCol] - getVal(hPrefSum, row, startCol - 1) != targetSum){
                            isValid = false;
                        }
                    }

                    for(int col = startCol; col <= endCol; ++col){
                        if(vPrefSum[endRow][col] - getVal(vPrefSum, startRow - 1, col) != targetSum){
                            isValid = false;
                        }
                    }

                    // update res
                    if(isValid){
                        res = max(res, k);
                    }
                }
            }
        }

        return res;
    }
};