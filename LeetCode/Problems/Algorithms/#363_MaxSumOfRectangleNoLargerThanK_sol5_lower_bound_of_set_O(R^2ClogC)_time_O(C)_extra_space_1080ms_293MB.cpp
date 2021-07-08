class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        int maxSum = INT_MIN;
        for(int row1 = 0; row1 < ROWS; ++row1){
            vector<int> colSum(COLS, 0);
            for(int row2 = row1; row2 < ROWS; ++row2){
                for(int col = 0; col < COLS; ++col){
                    colSum[col] += matrix[row2][col];
                }
                set<int> prefSums = {0};
                int prefSum = 0;
                for(int col = 0; col < COLS; ++col){
                    prefSum += colSum[col];
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