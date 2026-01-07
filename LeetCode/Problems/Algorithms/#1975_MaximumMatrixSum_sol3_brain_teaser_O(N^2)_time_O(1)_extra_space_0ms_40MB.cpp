class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        const int N = matrix.size();

        long long absSum = 0;
        int minAbsNum = abs(matrix[0][0]);
        int negativeNums = 0;

        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(matrix[row][col] < 0){
                    negativeNums += 1;
                }
                absSum += abs(matrix[row][col]);
                minAbsNum = min(minAbsNum, abs(matrix[row][col]));
            }
        }
        
        if(negativeNums % 2 == 0){
            return absSum;
        }

        return absSum - 2 * minAbsNum;
    }
};