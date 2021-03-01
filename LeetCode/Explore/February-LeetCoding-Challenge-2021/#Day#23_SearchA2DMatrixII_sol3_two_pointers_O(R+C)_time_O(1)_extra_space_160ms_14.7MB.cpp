class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        bool found = false;
        int row = 0;
        int col = COLS - 1;
        while(!found && row < ROWS && 0 <= col){
            if(matrix[row][col] == target){
                found = true;
            }else if(matrix[row][col] < target){
                row += 1;
            }else if(target < matrix[row][col]){
                col -= 1;
            }
        }
        return found;
    }
};