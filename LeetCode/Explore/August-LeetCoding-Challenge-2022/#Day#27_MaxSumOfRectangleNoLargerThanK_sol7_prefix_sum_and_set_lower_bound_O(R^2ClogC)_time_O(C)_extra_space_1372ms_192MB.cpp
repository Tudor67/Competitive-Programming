class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const int MIN_INF = INT_MIN;
        
        int maxSum = MIN_INF;
        vector<int> sumOf(COLS);
        set<int> sumSet;
        for(int row1 = 0; row1 < ROWS; ++row1){
            fill(sumOf.begin(), sumOf.end(), 0);
            for(int row2 = row1; row2 < ROWS; ++row2){
                for(int col = 0; col < COLS; ++col){
                    sumOf[col] += matrix[row2][col];
                }
                
                int prefSum = 0;
                sumSet.clear();
                sumSet.insert(0);
                for(int col = 0; col < COLS; ++col){
                    prefSum += sumOf[col];
                    set<int>::iterator it = sumSet.lower_bound(prefSum - k);
                    if(it != sumSet.end()){
                        int sum = prefSum - *it;
                        maxSum = max(maxSum, sum);
                    }
                    sumSet.insert(prefSum);
                }
                
                if(maxSum == k){
                    return maxSum;
                }
            }
        }
        
        return maxSum;
    }
};