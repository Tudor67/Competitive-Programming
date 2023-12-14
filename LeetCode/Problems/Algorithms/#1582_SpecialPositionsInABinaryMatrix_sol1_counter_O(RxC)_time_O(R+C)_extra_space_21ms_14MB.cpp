class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        vector<int> rowSum(ROWS);
        vector<int> colSum(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                rowSum[row] += mat[row][col];
                colSum[col] += mat[row][col];
            }
        }

        int specialPositions = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(mat[row][col] == 1 && rowSum[row] == 1 && colSum[col] == 1){
                    specialPositions += 1;
                }
            }
        }

        return specialPositions;
    }
};