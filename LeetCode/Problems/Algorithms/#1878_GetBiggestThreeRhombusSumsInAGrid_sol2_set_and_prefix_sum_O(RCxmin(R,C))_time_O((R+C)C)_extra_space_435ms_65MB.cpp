class Solution {
private:
    int getMainDiagIdx(int row, int col, const int& COLS){
        return row - col + (COLS - 1);
    }
    
    int getSecDiagIdx(int row, int col, const int& COLS){
        return row + col;
    }
    
    int getRangeSum(vector<int>& prefSum, const int& L, const int& R){
        if(L > R){
            return 0;
        }
        if(L <= 0){
            return prefSum[R];
        }
        return prefSum[R] - prefSum[L - 1];
    }
    
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int DIAGONALS = ROWS + COLS - 1;
        
        vector<vector<int>> mainDiagPrefSum(DIAGONALS, vector<int>(COLS));
        vector<vector<int>> secDiagPrefSum(DIAGONALS, vector<int>(COLS));
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int mainDiagIdx = getMainDiagIdx(row, col, COLS);
                if(col - 1 >= 0){
                    mainDiagPrefSum[mainDiagIdx][col] = mainDiagPrefSum[mainDiagIdx][col - 1];
                }
                mainDiagPrefSum[mainDiagIdx][col] += grid[row][col];
            }
        }
        
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = 0; col < COLS; ++col){
                int secDiagIdx = getSecDiagIdx(row, col, COLS);
                if(col - 1 >= 0){
                    secDiagPrefSum[secDiagIdx][col] = secDiagPrefSum[secDiagIdx][col - 1];
                }
                secDiagPrefSum[secDiagIdx][col] += grid[row][col];
            }
        }
        
        set<int> maxSums3;
        for(int centerRow = 0; centerRow < ROWS; ++centerRow){
            for(int centerCol = 0; centerCol < COLS; ++centerCol){
                for(int delta = 0; delta <= min({centerCol, COLS - 1 - centerCol, centerRow, ROWS - 1 - centerRow}); ++delta){
                    int sum = grid[centerRow][centerCol];
                    if(delta >= 1){
                        sum = getRangeSum(mainDiagPrefSum[getMainDiagIdx(centerRow - delta, centerCol, COLS)], centerCol, centerCol + delta) +
                              getRangeSum(mainDiagPrefSum[getMainDiagIdx(centerRow, centerCol - delta, COLS)], centerCol - delta, centerCol) +
                              getRangeSum(secDiagPrefSum[getSecDiagIdx(centerRow - 1, centerCol - delta + 1, COLS)], centerCol - delta + 1, centerCol - 1)+
                              getRangeSum(secDiagPrefSum[getSecDiagIdx(centerRow + delta - 1, centerCol + 1, COLS)], centerCol + 1, centerCol + delta - 1);
                    }
                    
                    maxSums3.insert(sum);
                    if((int)maxSums3.size() > 3){
                        maxSums3.erase(maxSums3.begin());
                    }
                }
            }
        }
        
        return vector<int>(maxSums3.rbegin(), maxSums3.rend());
    }
};