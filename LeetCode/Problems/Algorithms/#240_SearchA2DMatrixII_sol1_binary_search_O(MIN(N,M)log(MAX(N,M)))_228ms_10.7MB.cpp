class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        bool contains = false;
        if(N < M){
            for(int i = 0; !contains && i < N; ++i){
                int l = 0;
                int r = M - 1;
                while(l != r){
                    int mid = (l + r) / 2;
                    if(target <= matrix[i][mid]){
                        r = mid;
                    }else{
                        l = mid + 1;
                    }
                }
                contains |= (matrix[i][r] == target);
            }
        }else{
            for(int j = 0; !contains && j < M; ++j){
                int l = 0;
                int r = N - 1;
                while(l != r){
                    int mid = (l + r) / 2;
                    if(target <= matrix[mid][j]){
                        r = mid;
                    }else{
                        l = mid + 1;
                    }
                }
                contains |= (matrix[r][j] == target);
            }
        }
        
        return contains;
    }
};