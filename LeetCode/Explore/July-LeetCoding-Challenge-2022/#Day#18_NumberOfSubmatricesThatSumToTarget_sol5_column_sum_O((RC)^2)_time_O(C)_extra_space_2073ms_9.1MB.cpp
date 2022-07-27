class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        int res = 0;
        vector<int> colSum(COLS);
        for(int row1 = 0; row1 < ROWS; ++row1){
            for(int col1 = 0; col1 < COLS; ++col1){
                fill(colSum.begin(), colSum.end(), 0);
                for(int row2 = row1; row2 < ROWS; ++row2){
                    int submatrixSum = 0;
                    for(int col2 = col1; col2 < COLS; ++col2){
                        colSum[col2] += matrix[row2][col2];
                        submatrixSum += colSum[col2];
                        if(submatrixSum == target){
                            res += 1;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};