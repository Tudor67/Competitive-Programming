class Solution {
private:
    const long long MODULO = 1e9 + 7;
    using Matrix2D = vector<vector<long long>>;
    Matrix2D TEMP;
    
    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, Matrix2D& C){
        assert(!A.empty());
        assert(!B.empty());
        
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();
        
        assert(A_COLS == B_ROWS);
        
        const int TEMP_ROWS = A_ROWS;
        const int TEMP_COLS = B_COLS;
        if(TEMP.empty() || (int)TEMP.size() != TEMP_ROWS || (int)TEMP[0].size() != TEMP_COLS){
            TEMP.assign(TEMP_ROWS, vector<long long>(TEMP_COLS));
        }
        
        for(int row = 0; row < TEMP_ROWS; ++row){
            for(int col = 0; col < TEMP_COLS; ++col){
                TEMP[row][col] = 0;
                for(int k = 0; k < A_COLS; ++k){
                    TEMP[row][col] += (A[row][k] * B[k][col]);
                    TEMP[row][col] %= MODULO;
                }
            }
        }
        
        C = TEMP;
    }
    
    void matrixBinaryExponentiation(Matrix2D A, long long n, Matrix2D& RES){
        assert(!A.empty());
        assert(A.size() == A[0].size());
        
        const int SIZE = A.size();
        
        RES.assign(SIZE, vector<long long>(SIZE));
        for(int row = 0; row < SIZE; ++row){
            RES[row][row] = 1;
        }
        
        while(n > 0){
            if(n & 1){
                matrixMultiplication(A, RES, RES);
            }
            matrixMultiplication(A, A, A);
            n /= 2;
        }
    }
    
public:
    int numTilings(int N) {
        Matrix2D X = {{0, 0, 0, 1}};
        Matrix2D A = {{0, 1, 1, 1},
                      {0, 0, 1, 1},
                      {0, 1, 0, 1},
                      {1, 0, 0, 1}};
        
        Matrix2D A_POW_N;
        matrixBinaryExponentiation(A, N, A_POW_N);
        
        Matrix2D RES;
        matrixMultiplication(X, A_POW_N, RES);
        
        return RES[0][3];
    }
};