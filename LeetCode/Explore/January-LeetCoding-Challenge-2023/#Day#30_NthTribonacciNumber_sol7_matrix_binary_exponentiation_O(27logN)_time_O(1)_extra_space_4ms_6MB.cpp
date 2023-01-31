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

        const int RES_ROWS = A_ROWS;
        const int RES_COLS = B_COLS;
        if(TEMP.empty() || (int)TEMP.size() != RES_ROWS || (int)TEMP[0].size() != RES_COLS){
            TEMP.assign(RES_ROWS, vector<int>(RES_COLS));
        }

        for(int i = 0; i < RES_ROWS; ++i){
            for(int j = 0; j < RES_COLS; ++j){
                TEMP[i][j] = 0;
                for(int k = 0; k < B_ROWS; ++k){
                    TEMP[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        RES = TEMP;
    }

    void matrixBinaryExponentiation(Matrix2D A, int n, Matrix2D& RES){
        assert(A.size() == A[0].size());
        const int A_SIZE = A.size();

        RES.assign(A_SIZE, vector<int>(A_SIZE));
        for(int row = 0; row < A_SIZE; ++row){
            RES[row][row] = 1;
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
        if(n <= 1){
            return n;
        }

        Matrix2D X = {{0, 1, 1}};
        Matrix2D A = {{0, 0, 1},
                      {1, 0, 1},
                      {0, 1, 1}};
        
        Matrix2D A_POW_N;
        matrixBinaryExponentiation(A, n - 2, A_POW_N);

        Matrix2D RES;
        matrixMultiplication(X, A_POW_N, RES);

        return RES[0][2];
    }
};