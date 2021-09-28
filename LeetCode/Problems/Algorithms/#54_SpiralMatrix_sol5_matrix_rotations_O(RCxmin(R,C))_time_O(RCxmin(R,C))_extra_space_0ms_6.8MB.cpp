class Solution {
private:
    using Matrix = vector<vector<int>>;
    
    Matrix removeFirstRow(const Matrix& A){
        const int ROWS = A.size();
        const int COLS = A[0].size();
        Matrix matrix(ROWS - 1);
        for(int row = 1; row < ROWS; ++row){
            matrix[row - 1] = A[row];
        }
        return matrix;
    }
    
    Matrix counterClockwiseRotation90(const Matrix& A){
        const int ROWS = A.size();
        const int COLS = A[0].size();
        Matrix matrix(COLS, vector<int>(ROWS));
        for(int row = 0; row < (int)matrix.size(); ++row){
            for(int col = 0; col < (int)matrix[0].size(); ++col){
                matrix[row][col] = A[col][row];
            }
        }
        for(int row = 0; row < (int)matrix.size() / 2; ++row){
            for(int col = 0; col < (int)matrix[0].size(); ++col){
                swap(matrix[row][col], matrix[(int)matrix.size() - 1 - row][col]);
            }
        }
        return matrix;
    }
    
public:
    vector<int> spiralOrder(Matrix& initialMatrix) {
        const int ROWS = initialMatrix.size();
        const int COLS = initialMatrix[0].size();
        
        vector<int> spiralValues;
        Matrix matrix = initialMatrix;
        while(!matrix.empty()){
            vector<int>& firstRow = matrix[0];
            copy(firstRow.begin(), firstRow.end(), back_inserter(spiralValues));
            matrix = removeFirstRow(matrix);
            if(!matrix.empty()){
                matrix = counterClockwiseRotation90(matrix);
            }
        }
        
        return spiralValues;
    }
};