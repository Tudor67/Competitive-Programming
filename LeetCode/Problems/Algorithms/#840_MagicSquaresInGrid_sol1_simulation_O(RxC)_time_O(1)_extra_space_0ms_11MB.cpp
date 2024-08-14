class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid, int startRow, int startCol){
        const int TARGET_SUM = 15;

        int visMask = 1;
        for(int row = startRow; row < startRow + 3; ++row){
            for(int col = startCol; col < startCol + 3; ++col){
                visMask |= (1 << grid[row][col]);
            }
        }

        if(visMask != (1 << 10) - 1){
            return false;
        }

        for(int row = startRow; row < startRow + 3; ++row){
            int sum = 0;
            for(int col = startCol; col < startCol + 3; ++col){
                sum += grid[row][col];
            }
            if(sum != TARGET_SUM){
                return false;
            }
        }

        for(int col = startCol; col < startCol + 3; ++col){
            int sum = 0;
            for(int row = startRow; row < startRow + 3; ++row){
                sum += grid[row][col];
            }
            if(sum != TARGET_SUM){
                return false;
            }
        }

        if(grid[startRow][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol + 2] != TARGET_SUM){
            return false;
        }

        if(grid[startRow][startCol + 2] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol] != TARGET_SUM){
            return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int magicSquares = 0;
        for(int row = 0; row + 2 < ROWS; ++row){
            for(int col = 0; col + 2 < COLS; ++col){
                if(isMagicSquare(grid, row, col)){
                    magicSquares += 1;
                }
            }
        }

        return magicSquares;
    }
};