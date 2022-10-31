class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                if(matrix[row - 1][col - 1] != matrix[row][col]){
                    return false;
                }
            }
        }
        
        return true;
    }
};