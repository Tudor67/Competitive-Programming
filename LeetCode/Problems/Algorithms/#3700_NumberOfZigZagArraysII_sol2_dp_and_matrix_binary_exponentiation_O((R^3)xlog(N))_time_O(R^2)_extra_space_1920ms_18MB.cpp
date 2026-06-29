class Solution {
private:
    using Matrix2D = vector<vector<int>>;
    Matrix2D TEMP;

    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, Matrix2D& RES, const int MODULO){
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();

        assert(A_COLS == B_ROWS);

        const int RES_ROWS = A_ROWS;
        const int RES_COLS = B_COLS;

        if(RES_ROWS != (int)TEMP.size() || RES_COLS != (int)TEMP[0].size()){
            TEMP.assign(RES_ROWS, vector<int>(RES_COLS));
        }

        for(int i = 0; i < RES_ROWS; ++i){
            for(int j = 0; j < RES_COLS; ++j){
                TEMP[i][j] = 0;
                for(int k = 0; k < A_COLS; ++k){
                    TEMP[i][j] += ((long long)A[i][k] * (long long)B[k][j]) % MODULO;
                    TEMP[i][j] %= MODULO;
                }
            }
        }

        if(RES_ROWS != (int)RES.size() || RES_COLS != (int)RES[0].size()){
            RES.assign(RES_ROWS, vector<int>(RES_COLS));
        }

        for(int i = 0; i < RES_ROWS; ++i){
            for(int j = 0; j < RES_COLS; ++j){
                RES[i][j] = TEMP[i][j];
            }
        }
    }

    void matrixBinaryExponentiation(Matrix2D A, int n, Matrix2D& RES, const int MODULO){
        assert(A.size() == A[0].size());

        const int SIZE = A.size();
        RES.assign(SIZE, vector<int>(SIZE));
        for(int i = 0; i < SIZE; ++i){
            RES[i][i] = 1;
        }

        while(n > 0){
            if(n & 1){
                matrixMultiplication(RES, A, RES, MODULO);
            }
            matrixMultiplication(A, A, A, MODULO);
            n >>= 1;
        }
    }

public:
    int zigZagArrays(int N, int L, int R) {
        const int MODULO = 1'000'000'007;
        const int M = R - L + 1;

        Matrix2D X(1, vector<int>(2 * M, 1));

        Matrix2D T(2 * M, vector<int>(2 * M));
        for(int i = M; i < 2 * M; ++i){
            for(int j = 0; j < i - M; ++j){
                T[i][j] = 1;
            }
        }

        for(int i = 0; i < M; ++i){
            for(int j = i + M + 1; j < 2 * M; ++j){
                T[i][j] = 1;
            }
        }

        Matrix2D T_POW;
        matrixBinaryExponentiation(T, N - 1, T_POW, MODULO);

        Matrix2D RES;
        matrixMultiplication(X, T_POW, RES, MODULO);

        int res = 0;
        for(int i = 0; i < 2 * M; ++i){
            res += RES[0][i];
            res %= MODULO;
        }
        
        return res;
    }
};