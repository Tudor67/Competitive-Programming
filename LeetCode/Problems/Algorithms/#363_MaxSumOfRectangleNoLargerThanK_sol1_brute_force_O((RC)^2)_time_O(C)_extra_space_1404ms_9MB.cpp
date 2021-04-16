class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        int answer = INT_MIN;
        vector<int> colSum(COLS);
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                fill(colSum.begin(), colSum.end(), 0);
                for(int curRow = startRow; curRow < ROWS; ++curRow){
                    int curSum = 0;
                    for(int curCol = startCol; curCol < COLS; ++curCol){
                        colSum[curCol] += matrix[curRow][curCol];
                        curSum += colSum[curCol];
                        if(curSum <= k){
                            answer = max(curSum, answer);
                        }
                    }
                }
            }
        }
        
        return answer;
    }
};