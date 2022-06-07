class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<vector<int>> transposedMatrix(COLS, vector<int>(ROWS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                transposedMatrix[col][row] = matrix[row][col];
            }
        }
        
        return transposedMatrix;
    }
};