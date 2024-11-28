class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        long long res = 0;
        int minAbsVal = abs(matrix[0][0]);
        int negCount = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res += abs(matrix[row][col]);
                minAbsVal = min(minAbsVal, abs(matrix[row][col]));
                if(matrix[row][col] < 0){
                    negCount += 1;
                }
            }
        }

        if(negCount % 2 == 1){
            res -= 2 * minAbsVal;
        }

        return res;
    }
};