class Solution {
public:
    double champagneTower(int poured, int queryRow, int queryCol) {
        vector<vector<double>> f(queryRow + 2, vector<double>(queryRow + 2));
        f[0][0] = poured;
        for(int row = 0; row <= queryRow; ++row){
            for(int col = 0; col <= row; ++col){
                double excess = f[row][col] - 1;
                if(excess > 0){
                    f[row][col] -= excess;
                    f[row + 1][col] += excess / 2;
                    f[row + 1][col + 1] += excess / 2;
                }
            }
        }
        return f[queryRow][queryCol];
    }
};