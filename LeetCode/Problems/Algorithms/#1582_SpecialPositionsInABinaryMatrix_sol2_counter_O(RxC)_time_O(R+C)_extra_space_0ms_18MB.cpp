class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        vector<int> sumOfRow(ROWS);
        vector<int> sumOfCol(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                sumOfRow[row] += mat[row][col];
                sumOfCol[col] += mat[row][col];
            }
        }

        int specialPositions = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(mat[row][col] == 1 && sumOfRow[row] == 1 && sumOfCol[col] == 1){
                    specialPositions += 1;
                }
            }
        }

        return specialPositions;
    }
};