class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        int maxSum = INT_MIN;
        for(int col1 = 0; col1 < COLS; ++col1){
            vector<int> rowSum(ROWS, 0);
            for(int col2 = col1; col2 < COLS; ++col2){
                for(int row = 0; row < ROWS; ++row){
                    rowSum[row] += matrix[row][col2];
                }
                set<int> prefSums = {0};
                int prefSum = 0;
                for(int row = 0; row < ROWS; ++row){
                    prefSum += rowSum[row];
                    set<int>::iterator it = prefSums.lower_bound(prefSum - k);
                    if(it != prefSums.end()){
                        maxSum = max(prefSum - *it, maxSum);
                    }
                    prefSums.insert(prefSum);
                }
            }
        }
        
        return maxSum;
    }
};