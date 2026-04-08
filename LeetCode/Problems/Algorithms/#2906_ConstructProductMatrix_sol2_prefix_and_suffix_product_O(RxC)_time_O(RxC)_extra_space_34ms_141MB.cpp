class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MODULO = 12'345;

        vector<long long> prefProd;
        prefProd.reserve(ROWS * COLS + 1);
        prefProd.push_back(1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                prefProd.push_back(prefProd.back() * grid[row][col] % MODULO);
            }
        }

        vector<long long> suffProd;
        suffProd.reserve(ROWS * COLS + 1);
        suffProd.push_back(1);
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = COLS - 1; col >= 0; --col){
                suffProd.push_back(suffProd.back() * grid[row][col] % MODULO);
            }
        }

        reverse(suffProd.begin(), suffProd.end());

        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int idx = row * COLS + col;
                res[row][col] = prefProd[idx] * suffProd[idx + 1] % MODULO;
            }
        }

        return res;
    }
};