class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const int MIN_INF = INT_MIN;
        
        int maxSum = MIN_INF;
        vector<int> sumOf(ROWS);
        set<int> sumSet;
        for(int col1 = 0; col1 < COLS; ++col1){
            fill(sumOf.begin(), sumOf.end(), 0);
            for(int col2 = col1; col2 < COLS; ++col2){
                for(int row = 0; row < ROWS; ++row){
                    sumOf[row] += matrix[row][col2];
                }
                
                int prefSum = 0;
                sumSet.clear();
                sumSet.insert(0);
                for(int row = 0; row < ROWS; ++row){
                    prefSum += sumOf[row];
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