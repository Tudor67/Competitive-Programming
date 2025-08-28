class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> res = grid;
        vector<int> diag;

        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int row = startRow, col = 0; row < ROWS && col < COLS; ++row, ++col){
                diag.push_back(grid[row][col]);
            }

            sort(diag.begin(), diag.end());

            for(int row = startRow, col = 0; row < ROWS && col < COLS; ++row, ++col){
                res[row][col] = diag.back();
                diag.pop_back();
            }
        }

        for(int startCol = 1; startCol < COLS; ++startCol){
            for(int row = 0, col = startCol; row < ROWS && col < COLS; ++row, ++col){
                diag.push_back(grid[row][col]);
            }

            sort(diag.rbegin(), diag.rend());

            for(int row = 0, col = startCol; row < ROWS && col < COLS; ++row, ++col){
                res[row][col] = diag.back();
                diag.pop_back();
            }
        }

        return res;
    }
};