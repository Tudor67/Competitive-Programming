class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        
        long long absSum = 0;
        int negativesCount = 0;
        int minAbsVal = INT_MAX;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                absSum += abs(matrix[row][col]);
                minAbsVal = min(minAbsVal, abs(matrix[row][col]));
                negativesCount += (int)(matrix[row][col] < 0);
            }
        }
        
        long long maxSum = absSum;
        if(negativesCount % 2 == 1){
            maxSum = absSum - 2 * minAbsVal;
        }
        
        return maxSum;
    }
};