class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        vector<vector<int>> maxSide = matrix;
        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                if(matrix[row][col] == 1){
                    maxSide[row][col] = 1 + min({maxSide[row - 1][col - 1],
                                                 maxSide[row - 1][col],
                                                 maxSide[row][col - 1]});
                }else{
                    maxSide[row][col] = 0;
                }
            }
        }

        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res += maxSide[row][col];
            }
        }

        return res;
    }
};