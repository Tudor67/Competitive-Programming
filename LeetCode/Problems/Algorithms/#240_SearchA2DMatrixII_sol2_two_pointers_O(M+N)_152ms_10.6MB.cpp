class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        bool contains = false;
        for(int i = 0, j = M - 1; !contains && i < N && j >= 0;){
            if(matrix[i][j] == target){
                contains = true;
            }else if(matrix[i][j] < target){
                i += 1;
            }else if(matrix[i][j] > target){
                j -= 1;
            }
        }
        
        return contains;
    }
};