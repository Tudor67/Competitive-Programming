class Solution {
public:
    double champagneTower(int poured, int queryRow, int queryCol) {
        vector<vector<double>> f(2, vector<double>(queryRow + 2));
        f[0][0] = poured;
        for(int row = 0; row <= queryRow; ++row){
            fill(f[(row + 1) % 2].begin(), f[(row + 1) % 2].end(), 0);
            for(int col = 0; col <= row; ++col){
                double excess = f[row % 2][col] - 1;
                if(excess > 0){
                    f[row % 2][col] -= excess;
                    f[(row + 1) % 2][col] += excess / 2;
                    f[(row + 1) % 2][col + 1] += excess / 2;
                }
            }
        }
        return f[queryRow % 2][queryCol];
    }
};