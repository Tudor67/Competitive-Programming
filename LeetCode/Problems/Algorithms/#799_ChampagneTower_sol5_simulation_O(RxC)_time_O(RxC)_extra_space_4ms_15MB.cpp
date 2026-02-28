class Solution {
public:
    double champagneTower(int poured, int queryRow, int queryCol) {
        vector<vector<double>> c(queryRow + 2, vector<double>(queryCol + 2));

        c[0][0] = poured;
        for(int row = 0; row <= queryRow; ++row){
            for(int col = 0; col <= min(row, queryCol); ++col){
                double excess = max(0.0, c[row][col] - 1);
                c[row][col] -= excess;
                c[row + 1][col] += excess / 2;
                c[row + 1][col + 1] += excess / 2;
            }
        }

        return c[queryRow][queryCol];
    }
};