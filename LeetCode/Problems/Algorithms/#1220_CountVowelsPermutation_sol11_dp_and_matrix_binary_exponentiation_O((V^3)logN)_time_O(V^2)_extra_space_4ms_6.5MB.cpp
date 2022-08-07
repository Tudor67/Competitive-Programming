class Solution {
private:
    using Matrix2D = vector<vector<long long>>;
    const long long MODULO = 1e9 + 7;
    
    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, Matrix2D& RES, Matrix2D& TEMP){
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();
        assert(A_COLS == B_ROWS);
        
        if(A_ROWS != (int)TEMP.size() || B_COLS != (int)TEMP[0].size()){
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
    
    void matrixBinaryExponentiation(Matrix2D A, long long exponent, Matrix2D& RES){
        const int M = A.size();
        RES.assign(M, vector<long long>(M));
        for(int k = 0; k < M; ++k){
            RES[k][k] = 1;
        }
        
        Matrix2D TEMP;
        while(exponent > 0){
            if(exponent % 2 == 1){
                matrixMultiplication(A, RES, RES, TEMP);
            }
            exponent /= 2;
            if(exponent > 0){
                matrixMultiplication(A, A, A, TEMP);
            }
        }
    }
    
public:
    int countVowelPermutation(int N) {
        Matrix2D X = {{1, 1, 1, 1, 1}};
        Matrix2D A = {{0, 1, 0, 0, 0},
                      {1, 0, 1, 0, 0},
                      {1, 1, 0, 1, 1},
                      {0, 0, 1, 0, 1},
                      {1, 0, 0, 0, 0}};
        
        Matrix2D A_POW_N;
        matrixBinaryExponentiation(A, N - 1, A_POW_N);
        
        Matrix2D RES;
        Matrix2D TEMP;
        matrixMultiplication(X, A_POW_N, RES, TEMP);
        
        int stringsCount = 0;
        for(int col = 0; col < (int)RES[0].size(); ++col){
            stringsCount += RES[0][col];
            stringsCount %= MODULO;
        }
        
        return stringsCount;
    }
};