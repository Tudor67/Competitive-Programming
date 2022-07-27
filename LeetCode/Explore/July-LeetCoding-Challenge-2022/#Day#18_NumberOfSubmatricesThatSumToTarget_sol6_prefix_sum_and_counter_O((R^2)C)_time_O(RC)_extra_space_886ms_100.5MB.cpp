class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<vector<int>> colPrefixSum(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0){
                    colPrefixSum[row][col] = matrix[row][col];
                }else{
                    colPrefixSum[row][col] = colPrefixSum[row - 1][col] + matrix[row][col];
                }
            }
        }
        
        int res = 0;
        unordered_map<int, int> count;
        for(int row1 = 0; row1 < ROWS; ++row1){
            for(int row2 = row1; row2 < ROWS; ++row2){
                count.clear();
                count[0] = 1;
                int prefixSum = 0;
                for(int col = 0; col < COLS; ++col){
                    prefixSum += colPrefixSum[row2][col] - (row1 == 0 ? 0 : colPrefixSum[row1 - 1][col]);
                    if(count.count(prefixSum - target)){
                        res += count[prefixSum - target];
                    }
                    count[prefixSum] += 1;
                }
            }
        }
        
        return res;
    }
};