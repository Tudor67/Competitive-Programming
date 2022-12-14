class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        // minSum[row][col]: min sum of a falling path ending at cell (row, col)
        vector<vector<int>> minSum(ROWS, vector<int>(COLS));
        minSum[0] = matrix[0];
        for(int row = 1; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int prevMinSum = minSum[row - 1][col];
                if(col - 1 >= 0){
                    prevMinSum = min(prevMinSum, minSum[row - 1][col - 1]);
                }
                if(col + 1 < COLS){
                    prevMinSum = min(prevMinSum, minSum[row - 1][col + 1]);
                }
                minSum[row][col] = matrix[row][col] + prevMinSum;
            }
        }

        return *min_element(minSum[ROWS - 1].begin(), minSum[ROWS - 1].end());
    }
};