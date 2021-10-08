class Solution {
private:
    using Matrix2D = vector<vector<int>>;
    
    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, Matrix2D& C){
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();
        assert(A_COLS == B_ROWS);
        
        static Matrix2D TEMP;
        if(A_ROWS != (int)TEMP.size() || B_COLS != (int)TEMP[0].size()){
            TEMP.clear();
            TEMP.resize(A_ROWS, vector<int>(B_COLS));
        }
        const int TEMP_ROWS = TEMP.size();
        const int TEMP_COLS = TEMP[0].size();
        
        for(int i = 0; i < TEMP_ROWS; ++i){
            for(int j = 0; j < TEMP_COLS; ++j){
                TEMP[i][j] = 0;
                for(int k = 0; k < B_ROWS; ++k){
                    TEMP[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        C = TEMP;
    }
    
    void matrixBinaryExponentiation(Matrix2D A, int n, Matrix2D& RES){
        const int M = A.size();
        assert(A.size() == A[0].size());
        
        RES.clear();
        RES.resize(M, vector<int>(M, 0));
        for(int i = 0; i < M; ++i){
            RES[i][i] = 1;
        }
        
        while(n > 0){
            if(n & 1){
                matrixMultiplication(RES, A, RES);
            }
            n /= 2;
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
        
        Matrix2D A_POW;
        matrixBinaryExponentiation(A, n - 1, A_POW);
        
        Matrix2D RES;
        matrixMultiplication(X, A_POW, RES);
        
        return RES[0][1];
    }
};