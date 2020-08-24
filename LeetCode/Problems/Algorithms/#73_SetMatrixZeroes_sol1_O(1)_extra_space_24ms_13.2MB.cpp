class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        bool is_zero_row = false;
        for(int j = 0; j < M; ++j){
            if(matrix[0][j] == 0){
                is_zero_row = true;
            }
        }
        
        bool is_zero_col = false;
        for(int i = 0; i < N; ++i){
            if(matrix[i][0] == 0){
                is_zero_col = true;
            }
        }
        
        for(int i = 1; i < N; ++i){
            for(int j = 1; j < M; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < N; ++i){
            for(int j = 1; j < M; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(is_zero_row){
            for(int j = 0; j < M; ++j){
                matrix[0][j] = 0;
            }
        }
        
        if(is_zero_col){
            for(int i = 0; i < N; ++i){
                matrix[i][0] = 0;
            }
        }
    }
};