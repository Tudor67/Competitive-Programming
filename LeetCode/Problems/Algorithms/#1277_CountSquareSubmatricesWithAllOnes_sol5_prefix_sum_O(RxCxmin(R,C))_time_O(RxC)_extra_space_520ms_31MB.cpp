class Solution {
private:
    int getVal(vector<vector<int>>& matrix, int row, int col){
        if(0 <= row && row < (int)matrix.size() && 0 <= col && col < (int)matrix[0].size()){
            return matrix[row][col];
        }
        return 0;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        vector<vector<int>> prefSum(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                prefSum[row][col] = matrix[row][col]
                                    + getVal(prefSum, row - 1, col)
                                    + getVal(prefSum, row, col - 1)
                                    - getVal(prefSum, row - 1, col - 1);
            }
        }

        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int len = 1; row + len - 1 < ROWS && col + len - 1 < COLS; ++len){
                    int ones = prefSum[row + len - 1][col + len - 1]
                               - getVal(prefSum, row - 1, col + len - 1)
                               - getVal(prefSum, row + len - 1, col - 1)
                               + getVal(prefSum, row - 1, col - 1);
                    if(ones == len * len){
                        res += 1;
                    }
                }
            }
        }

        return res;
    }
};