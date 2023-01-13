class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int res = 1;
        vector<int> hSum(ROWS);
        vector<int> vSum(COLS);
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                fill(hSum.begin(), hSum.end(), 0);
                fill(vSum.begin(), vSum.end(), 0);
                for(int k = 1; k <= min(ROWS - startRow, COLS - startCol); ++k){
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
                        if(row < endRow){
                            hSum[row] += grid[row][endCol];
                        }else{
                            for(int col = startCol; col <= endCol; ++col){
                                hSum[row] += grid[row][col];
                            }
                        }
                        if(hSum[row] != targetSum){
                            isValid = false;
                        }
                    }

                    for(int col = startCol; col <= endCol; ++col){
                        if(col < endCol){
                            vSum[col] += grid[endRow][col];
                        }else{
                            for(int row = startRow; row <= endRow; ++row){
                                vSum[col] += grid[row][col];
                            }
                        }
                        if(vSum[col] != targetSum){
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