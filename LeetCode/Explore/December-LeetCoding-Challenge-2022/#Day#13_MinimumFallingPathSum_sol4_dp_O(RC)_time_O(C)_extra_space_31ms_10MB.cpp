class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        // At iteration row:
        //    minSum[row % 2][col]: min sum of a falling path ending at cell (row, col)
        vector<vector<int>> minSum(2, vector<int>(COLS));
        minSum[0] = matrix[0];
        for(int row = 1; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int prevMinSum = minSum[(row - 1) % 2][col];
                if(col - 1 >= 0){
                    prevMinSum = min(prevMinSum, minSum[(row - 1) % 2][col - 1]);
                }
                if(col + 1 < COLS){
                    prevMinSum = min(prevMinSum, minSum[(row - 1) % 2][col + 1]);
                }
                minSum[row % 2][col] = matrix[row][col] + prevMinSum;
            }
        }

        return *min_element(minSum[(ROWS - 1) % 2].begin(), minSum[(ROWS - 1) % 2].end());
    }
};