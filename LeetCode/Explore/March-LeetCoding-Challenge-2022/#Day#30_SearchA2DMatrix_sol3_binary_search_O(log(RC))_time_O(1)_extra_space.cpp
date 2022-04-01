class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        int l = 0;
        int r = ROWS * COLS - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(matrix[mid / COLS][mid % COLS] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        return (matrix[r / COLS][r % COLS] == target);
    }
};