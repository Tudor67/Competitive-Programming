class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid, int startRow, int startCol, int targetSqSide,
                       vector<vector<int>>& hSuffSum, vector<vector<int>>& vSuffSum){
        int mainDiagSum = 0;
        int secondDiagSum = 0;
        for(int i = 0; i < targetSqSide; ++i){
            mainDiagSum += grid[startRow + i][startCol + i];
            secondDiagSum += grid[startRow + i][startCol + targetSqSide - 1 - i];
        }

        if(mainDiagSum != secondDiagSum){
            return false;
        }

        for(int i = 0; i < targetSqSide; ++i){
            int rowSum = hSuffSum[startRow + i][startCol] - hSuffSum[startRow + i][startCol + targetSqSide];
            int colSum = vSuffSum[startRow][startCol + i] - vSuffSum[startRow + targetSqSide][startCol + i];
            if(rowSum != mainDiagSum || colSum != mainDiagSum){
                return false;
            }
        }

        return true;
    }

    bool containsMagicSquare(vector<vector<int>>& grid, int targetSqSide,
                             vector<vector<int>>& hSuffSum, vector<vector<int>>& vSuffSum){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        for(int startRow = 0; startRow + targetSqSide - 1 < ROWS; ++startRow){
            for(int startCol = 0; startCol + targetSqSide - 1 < COLS; ++startCol){
                if(isMagicSquare(grid, startRow, startCol, targetSqSide, hSuffSum, vSuffSum)){
                    return true;
                }
            }
        }
        
        return false;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> hSuffSum(ROWS, vector<int>(COLS + 1, 0));
        vector<vector<int>> vSuffSum(ROWS + 1, vector<int>(COLS, 0));
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = COLS - 1; col >= 0; --col){
                hSuffSum[row][col] = grid[row][col] + hSuffSum[row][col + 1];
                vSuffSum[row][col] = grid[row][col] + vSuffSum[row + 1][col];
            }
        }

        for(int targetSqSide = min(ROWS, COLS); targetSqSide >= 1; --targetSqSide){
            if(containsMagicSquare(grid, targetSqSide, hSuffSum, vSuffSum)){
                return targetSqSide;
            }
        }

        return 0;
    }
};