class Solution {
private:
    using Matrix2D = vector<vector<int>>;
    const Matrix2D I2 = {{1, 0}, {0, 1}};
    const Matrix2D O2 = {{0, 0}, {0, 0}};
    
    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, Matrix2D& RES){
        static Matrix2D TEMP = O2;
        for(int row = 0; row < 2; ++row){
            for(int col = 0; col < 2; ++col){
                TEMP[row][col] = 0;
                for(int k = 0; k < 2; ++k){
                    TEMP[row][col] += A[row][k] * B[k][col];
                }
            }
        }
        RES = TEMP;
    }
    
    void matrixBinaryExponentiation(Matrix2D A, int n, Matrix2D& RES){
        RES = I2;
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
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        
        Matrix2D A = {{0, 1}, {1, 1}};
        Matrix2D RES;
        matrixBinaryExponentiation(A, n - 1, RES);
        
        int fibN = RES[1][1];
        
        return fibN;
    }
};