class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MODULO = 12'345;

        vector<vector<int>> res(ROWS, vector<int>(COLS));

        long long prefProd = 1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[row][col] = prefProd;
                prefProd = prefProd * grid[row][col] % MODULO;
            }
        }

        long long suffProd = 1;
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = COLS - 1; col >= 0; --col){
                res[row][col] = res[row][col] * suffProd % MODULO;
                suffProd = suffProd * grid[row][col] % MODULO;
            }
        }

        return res;
    }
};