class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        int l = 0;
        int r = N * M - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(target <= matrix[mid / M][mid % M]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return (matrix[r / M][r % M] == target);
    }
};