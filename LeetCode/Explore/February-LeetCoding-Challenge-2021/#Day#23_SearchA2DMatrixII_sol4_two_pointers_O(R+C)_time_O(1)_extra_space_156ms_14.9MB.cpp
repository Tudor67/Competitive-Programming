class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        bool found = false;
        int row = ROWS - 1;
        int col = 0;
        while(!found && 0 <= row && col < COLS){
            if(matrix[row][col] == target){
                found = true;
            }else if(matrix[row][col] < target){
                col += 1;
            }else if(target < matrix[row][col]){
                row -= 1;
            }
        }
        return found;
    }
};