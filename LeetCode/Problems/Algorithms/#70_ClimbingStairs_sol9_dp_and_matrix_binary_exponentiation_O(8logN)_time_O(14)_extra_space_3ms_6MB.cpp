class Solution {
private:
    using Matrix2D = vector<vector<int>>;
    Matrix2D TEMP;

    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, Matrix2D& RES){
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();
        assert(A_COLS == B_ROWS);
        
        if((int)TEMP.size() != A_ROWS || (int)TEMP[0].size() != B_COLS){
            TEMP.assign(A_ROWS, vector<int>(B_COLS));
        }

        for(int row = 0; row < A_ROWS; ++row){
            for(int col = 0; col < B_COLS; ++col){
                TEMP[row][col] = 0;
                for(int k = 0; k < B_ROWS; ++k){
                    TEMP[row][col] += A[row][k] * B[k][col];
                }
            }
        }

        RES = TEMP;
    }

    void matrixBinaryExponentiation(Matrix2D A, int n, Matrix2D& RES){
        assert(A.size() == A[0].size());
        const int A_SIZE = A.size();

        RES.assign(A_SIZE, vector<int>(A_SIZE, 0));
        for(int row = 0; row < A_SIZE; ++row){
            RES[row][row] = 1;
        }

        while(n > 0){
            if(n & 1){
                matrixMultiplication(A, RES, RES);
            }
            n >>= 1;
            if(n > 0){
                matrixMultiplication(A, A, A);
            }
        }
    }

public:
    int climbStairs(int n) {
        Matrix2D X = {{1, 1}};
        Matrix2D A = {{0, 1},
                      {1, 1}};
        
        Matrix2D A_POW_N;
        matrixBinaryExponentiation(A, n - 1, A_POW_N);

        Matrix2D RES;
        matrixMultiplication(X, A_POW_N, RES);

        return RES[0][1];
    }
};