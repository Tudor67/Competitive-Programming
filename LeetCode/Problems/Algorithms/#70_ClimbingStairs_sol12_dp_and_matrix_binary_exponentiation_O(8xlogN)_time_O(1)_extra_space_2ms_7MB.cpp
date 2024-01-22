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

        if(A_ROWS != (int)TEMP.size() || B_COLS != (int)TEMP[0].size()){
            TEMP.assign(A_ROWS, vector<int>(B_COLS));
        }

        for(int i = 0; i < A_ROWS; ++i){
            for(int j = 0; j < B_COLS; ++j){
                TEMP[i][j] = 0;
                for(int k = 0; k < A_COLS; ++k){
                    TEMP[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        RES = TEMP;
    }

    void matrixBinaryExponentiation(Matrix2D A, int n, Matrix2D& RES){
        const int A_SIZE = A.size();
        assert(A.size() == A[0].size());

        RES.assign(A_SIZE, vector<int>(A_SIZE));
        for(int i = 0; i < A_SIZE; ++i){
            RES[i][i] = 1;
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
    int climbStairs(int N) {
        Matrix2D X = {{1, 1}};
        Matrix2D A = {{0, 1},
                      {1, 1}};

        Matrix2D A_POW_N;
        matrixBinaryExponentiation(A, N - 1, A_POW_N);

        Matrix2D RES;
        matrixMultiplication(X, A_POW_N, RES);

        return RES[0][1];
    }
};