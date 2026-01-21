class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid, int startRow, int startCol, int targetSqSide){
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
            int rowSum = 0;
            int colSum = 0;
            for(int j = 0; j < targetSqSide; ++j){
                rowSum += grid[startRow + i][startCol + j];
                colSum += grid[startRow + j][startCol + i];
            }
            if(rowSum != mainDiagSum || colSum != mainDiagSum){
                return false;
            }
        }

        return true;
    }

    bool containsMagicSquare(vector<vector<int>>& grid, int targetSqSide){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        for(int startRow = 0; startRow + targetSqSide - 1 < ROWS; ++startRow){
            for(int startCol = 0; startCol + targetSqSide - 1 < COLS; ++startCol){
                if(isMagicSquare(grid, startRow, startCol, targetSqSide)){
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

        for(int targetSqSide = min(ROWS, COLS); targetSqSide >= 1; --targetSqSide){
            if(containsMagicSquare(grid, targetSqSide)){
                return targetSqSide;
            }
        }

        return 0;
    }
};