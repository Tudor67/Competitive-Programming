class Solution {
private:
    using Matrix2D = vector<vector<int>>;
    
    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, Matrix2D& C){
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();
        assert(A_COLS == B_ROWS);
        
        static Matrix2D AUX;
        if(A_ROWS != (int)AUX.size() || B_COLS != (int)AUX[0].size()){
            AUX.clear();
            AUX.resize(A_ROWS, vector<int>(B_COLS));
        }
        const int AUX_ROWS = AUX.size();
        const int AUX_COLS = AUX[0].size();
        
        for(int i = 0; i < AUX_ROWS; ++i){
            for(int j = 0; j < AUX_COLS; ++j){
                AUX[i][j] = 0;
                for(int k = 0; k < B_ROWS; ++k){
                    AUX[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        C = AUX;
    }
    
    void matrixBinaryExponentiation(Matrix2D A, int n, Matrix2D& RES){
        assert(n > 0);
        
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        assert(A_ROWS == A_COLS);
        
        const int M = A_ROWS;
        RES.clear();
        RES.resize(M, vector<int>(M, 0));
        for(int i = 0; i < M; ++i){
            RES[i][i] = 1;
        }
        
        while(n > 0){
            if(n & 1){
                matrixMultiplication(A, RES, RES);
            }
            n /= 2;
            if(n > 0){
                matrixMultiplication(A, A, A);
            }
        }
    }
    
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        
        if(n <= 2){
            return 1;
        }
        
        Matrix2D X = {{0, 1, 1}};
        Matrix2D A = {{0, 0, 1},
                      {1, 0, 1},
                      {0, 1, 1}};
        
        Matrix2D A_POW;
        matrixBinaryExponentiation(A, n - 2, A_POW);
        
        Matrix2D RES;
        matrixMultiplication(X, A_POW, RES);
        
        return RES[0][2];
    }
};