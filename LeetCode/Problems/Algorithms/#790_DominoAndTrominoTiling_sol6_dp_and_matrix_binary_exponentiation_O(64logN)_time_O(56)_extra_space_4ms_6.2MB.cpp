class Solution {
private:
    const int MODULO = 1e9 + 7;
    using Matrix2D = vector<vector<long long>>;
    Matrix2D TEMP;

    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, Matrix2D& RES){
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();
        assert(A_COLS == B_ROWS);

        if((int)TEMP.size() != A_ROWS || (int)TEMP[0].size() != B_COLS){
            TEMP.assign(A_ROWS, vector<long long>(B_COLS));
        }

        for(int row = 0; row < A_ROWS; ++row){
            for(int col = 0; col < B_COLS; ++col){
                TEMP[row][col] = 0;
                for(int k = 0; k < B_ROWS; ++k){
                    TEMP[row][col] += A[row][k] * B[k][col];
                    TEMP[row][col] %= MODULO;
                }
            }
        }

        RES = TEMP;
    }

    void matrixBinaryExponentiation(Matrix2D A, int n, Matrix2D& RES){
        assert(A.size() == A[0].size());
        const int SIZE = A.size();

        RES.assign(SIZE, vector<long long>(SIZE));
        for(int i = 0; i < SIZE; ++i){
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
    int numTilings(int N) {
        if(N <= 2){
            return N;
        }

        // Configs:
        // Config 0  Config 1  Config 2
        //   10        11        11
        //   11        10        11

        // dp[i][c]: number of ways to tile an 2 x i board
        //           when the last config is c
        // 
        //                             X                                        A
        // [[dp[i - 2][2], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]]]  *  [[0, 1, 1, 1],
        //                                                                 [0, 0, 1, 1],
        //                                                                 [0, 1, 0, 1],  =
        //                                                                 [1, 0, 0, 1]]
        // 
        //                             Y
        // [[dp[i - 1][2], dp[i][0], dp[i][1], dp[i][2]]]

        Matrix2D X = {{1, 1, 1, 2}};
        Matrix2D A = {{0, 1, 1, 1},
                      {0, 0, 1, 1},
                      {0, 1, 0, 1},
                      {1, 0, 0, 1}};
        
        Matrix2D A_POW_N;
        matrixBinaryExponentiation(A, N - 2, A_POW_N);

        Matrix2D RES;
        matrixMultiplication(X, A_POW_N, RES);

        return RES[0][3];
    }
};