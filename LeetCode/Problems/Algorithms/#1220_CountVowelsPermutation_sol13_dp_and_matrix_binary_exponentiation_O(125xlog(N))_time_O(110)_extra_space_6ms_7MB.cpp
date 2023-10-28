class Solution {
private:
    using Matrix2D = vector<vector<long long>>;
    Matrix2D TEMP;

    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, Matrix2D& C, const long long& MODULO){
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();

        assert(A_COLS == B_ROWS);

        if((int)TEMP.size() != A_ROWS || (int)TEMP[0].size() != B_COLS){
            TEMP.assign(A_ROWS, vector<long long>(B_COLS));
        }

        for(int i = 0; i < A_ROWS; ++i){
            for(int j = 0; j < B_COLS; ++j){
                TEMP[i][j] = 0;
                for(int k = 0; k < A_COLS; ++k){
                    TEMP[i][j] += A[i][k] * B[k][j];
                    TEMP[i][j] %= MODULO;
                }
            }
        }

        C = TEMP;
    }

    void matrixBinaryExponentiation(Matrix2D A, long long n, Matrix2D& RES, const long long& MODULO){
        assert(A.size() == A[0].size());

        const int A_SIZE = A.size();

        RES.assign(A_SIZE, vector<long long>(A_SIZE, 0));
        for(int i = 0; i < A_SIZE; ++i){
            RES[i][i] = 1;
        }

        while(n > 0){
            if(n & 1){
                matrixMultiplication(A, RES, RES, MODULO);
            }
            matrixMultiplication(A, A, A, MODULO);
            n /= 2;
        }
    }

public:
    int countVowelPermutation(int n) {
        const long long MODULO = 1e9 + 7;

        Matrix2D X = {{1, 1, 1, 1, 1}};
        Matrix2D A = {{0, 1, 0, 0, 0},
                      {1, 0, 1, 0, 0},
                      {1, 1, 0, 1, 1},
                      {0, 0, 1, 0, 1},
                      {1, 0, 0, 0, 0}};

        Matrix2D A_POW_N;
        matrixBinaryExponentiation(A, n - 1, A_POW_N, MODULO);

        Matrix2D RES;
        matrixMultiplication(X, A_POW_N, RES, MODULO);

        return accumulate(RES[0].begin(), RES[0].end(), (long long)0) % MODULO;
    }
};