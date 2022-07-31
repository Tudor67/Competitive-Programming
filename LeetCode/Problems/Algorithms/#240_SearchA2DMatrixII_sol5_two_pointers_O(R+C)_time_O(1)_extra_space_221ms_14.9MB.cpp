class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        int row = 0;
        int col = COLS - 1;
        while(0 <= row && row < ROWS && 0 <= col && col < COLS){
            if(matrix[row][col] < target){
                row += 1;
            }else if(matrix[row][col] > target){
                col -= 1;
            }else if(matrix[row][col] == target){
                return true;
            }
        }
        
        return false;
    }
};