class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MODULO = 12345;
        
        vector<vector<int>> res(ROWS, vector<int>(COLS));

        // Step 1: prefix product
        long long p = 1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[row][col] = p;
                p = (p * grid[row][col]) % MODULO;
            }
        }
        
        // Step 2: suffix product
        p = 1;
        for(int row = ROWS -1; row >= 0; --row){
            for(int col = COLS - 1; col >= 0; --col){
                res[row][col] = (res[row][col] * p) % MODULO;
                p = (p * grid[row][col]) % MODULO;
            }
        }
        
        return res;
    }
};