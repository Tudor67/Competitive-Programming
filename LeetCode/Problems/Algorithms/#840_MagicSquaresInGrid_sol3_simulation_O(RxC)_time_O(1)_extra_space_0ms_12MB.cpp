class Solution {
private:
    bool isMagicSquare(int startRow, int startCol, vector<vector<int>>& grid){
        int visMask = 0;
        for(int row = startRow; row < startRow + 3; ++row){
            for(int col = startCol; col < startCol + 3; ++col){
                if(!(1 <= grid[row][col] && grid[row][col] <= 9)){
                    return false;
                }
                if((visMask >> grid[row][col]) & 1){
                    return false;
                }
                visMask |= (1 << grid[row][col]);
            }
        }

        if(grid[startRow][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol + 2] != 15 ||
           grid[startRow][startCol + 2] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol] != 15){
            return false;
        }

        if(grid[startRow][startCol] + grid[startRow][startCol + 1] + grid[startRow][startCol + 2] != 15 ||
           grid[startRow + 1][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow + 1][startCol + 2] != 15){
            return false;
        }

        if(grid[startRow][startCol] + grid[startRow + 1][startCol] + grid[startRow + 2][startCol] != 15 ||
           grid[startRow][startCol + 1] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol + 1] != 15){
            return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int magicSquares = 0;
        for(int startRow = 0; startRow + 2 < ROWS; ++startRow){
            for(int startCol = 0; startCol + 2 < COLS; ++startCol){
                if(isMagicSquare(startRow, startCol, grid)){
                    magicSquares += 1;
                }
            }
        }

        return magicSquares;
    }
};