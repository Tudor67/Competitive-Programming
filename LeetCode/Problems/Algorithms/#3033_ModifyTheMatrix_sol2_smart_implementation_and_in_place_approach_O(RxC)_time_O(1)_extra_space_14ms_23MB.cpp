class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        for(int col = 0; col < COLS; ++col){
            int maxVal = -1;
            int prevSpecialRow = -1;
            for(int row = 0; row < ROWS; ++row){
                maxVal = max(maxVal, matrix[row][col]);
                if(matrix[row][col] == -1){
                    matrix[row][col] = prevSpecialRow;
                    prevSpecialRow = row;
                }
            }
            while(prevSpecialRow != -1){
                int row = prevSpecialRow;
                prevSpecialRow = matrix[prevSpecialRow][col];
                matrix[row][col] = maxVal;
            }
        }
        
        return matrix;
    }
};