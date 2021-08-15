class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        bool isFirstRowZero = false;
        for(int col = 0; col < COLS; ++col){
            if(matrix[0][col] == 0){
                isFirstRowZero = true;
            }
        }
        
        bool isFirstColZero = false;
        for(int row = 0; row < ROWS; ++row){
            if(matrix[row][0] == 0){
                isFirstColZero = true;
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(matrix[row][col] == 0){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        
        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                if(matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
        }
        
        if(isFirstRowZero){
            for(int col = 0; col < COLS; ++col){
                matrix[0][col] = 0;
            }
        }
        
        if(isFirstColZero){
            for(int row = 0; row < ROWS; ++row){
                matrix[row][0] = 0;
            }
        }
    }
};