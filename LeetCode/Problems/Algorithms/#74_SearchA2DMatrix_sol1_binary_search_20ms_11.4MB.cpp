class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool contains = false;
        
        if(!matrix.empty() && !matrix[0].empty()){
            const int N = matrix.size();
            const int M = matrix[0].size();
            
            int l = 0;
            int r = N * M - 1;
            while(l != r){
                int mid = (l + r) / 2;
                int row = mid / M;
                int col = mid % M;
                if(target <= matrix[row][col]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            
            contains = (matrix[r / M][r % M] == target);
        }
        
        return contains;
    }
};