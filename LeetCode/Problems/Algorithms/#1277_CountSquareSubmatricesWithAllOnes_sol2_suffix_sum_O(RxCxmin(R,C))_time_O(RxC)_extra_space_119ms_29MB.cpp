class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        vector<vector<int>> suffSum(ROWS + 1, vector<int>(COLS + 1));
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = COLS - 1; col >= 0; --col){
                suffSum[row][col] = matrix[row][col]
                                    + suffSum[row + 1][col]
                                    + suffSum[row][col + 1]
                                    - suffSum[row + 1][col + 1];
            }
        }

        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int k = 1; matrix[row][col] == 1 && row + k - 1 < ROWS && col + k - 1 < COLS; ++k){
                    int ones = suffSum[row][col]
                               - suffSum[row + k][col]
                               - suffSum[row][col + k]
                               + suffSum[row + k][col + k];
                    if(ones == k * k){
                        res += 1;
                    }
                }
            }
        }

        return res;
    }
};