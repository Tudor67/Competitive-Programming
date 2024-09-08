class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int ROWS, int COLS) {
        const int N = original.size();

        if(N != ROWS * COLS){
            return {};
        }

        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[row][col] = original[row * COLS + col];
            }
        }

        return res;
    }
};