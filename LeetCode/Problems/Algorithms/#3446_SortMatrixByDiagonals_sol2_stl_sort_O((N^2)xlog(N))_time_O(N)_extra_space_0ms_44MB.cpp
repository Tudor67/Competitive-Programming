class Solution {
private:
    void sortDiagonal(int startRow, int startCol, vector<vector<int>>& grid, bool incOrder){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<int> diag;
        for(int row = startRow, col = startCol; row < ROWS && col < COLS; ++row, ++col){
            diag.push_back(grid[row][col]);
        }

        sort(diag.begin(), diag.end());

        if(!incOrder){
            reverse(diag.begin(), diag.end());
        }

        for(int row = startRow, col = startCol; row < ROWS && col < COLS; ++row, ++col){
            grid[row][col] = diag[min(row, col)];
        }
    }

public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> res = grid;
        for(int startRow = 0; startRow < ROWS; ++startRow){
            sortDiagonal(startRow, 0, res, false);
        }

        for(int startCol = 1; startCol < COLS; ++startCol){
            sortDiagonal(0, startCol, res, true);
        }

        return res;
    }
};