class Solution {
private:
    using Matrix = vector<vector<int>>;
    
    void matrixMultiplication(const Matrix& A, const Matrix& B, Matrix& RES, const int& MODULO){
        assert(!A.empty() && !B.empty());
        assert(A[0].size() == B.size());
        
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();
        
        static Matrix TEMP;
        if((int)TEMP.size() != A_ROWS || (int)TEMP[0].size() != B_COLS){
            TEMP.clear();
            TEMP.resize(A_ROWS, vector<int>(B_COLS));
        }
        
        for(int row = 0; row < A_ROWS; ++row){
            for(int col = 0; col < B_COLS; ++col){
                TEMP[row][col] = 0;
                for(int k = 0; k < A_COLS; ++k){
                    TEMP[row][col] += (A[row][k] * 1LL * B[k][col]) % MODULO;
                    TEMP[row][col] %= MODULO;
                }
            }
        }
        
        RES = TEMP;
    }
    
    void matrixBinaryExponentiation(Matrix A, int n, Matrix& RES, const int& MODULO){
        assert(!A.empty());
        assert(A.size() == A[0].size());
        
        const int M = A.size();
        Matrix TEMP(M, vector<int>(M, 0));
        for(int row = 0; row < M; ++row){
            TEMP[row][row] = 1;
        }
        
        while(n > 0){
            if(n & 1){
                matrixMultiplication(TEMP, A, TEMP, MODULO);
            }
            matrixMultiplication(A, A, A, MODULO);
            n /= 2;
        }
        
        RES = TEMP;
    }
    
public:
    int countVowelPermutation(int n) {
        const int MODULO = 1e9 + 7;
        
        Matrix A = {
            {0, 1, 1, 0, 1}, // 0 e i 0 u
            {1, 0, 1, 0, 0}, // a 0 i 0 0
            {0, 1, 0, 1, 0}, // 0 e 0 o 0
            {0, 0, 1, 0, 0}, // 0 0 i 0 0
            {0, 0, 1, 1, 0}  // 0 0 i o 0
        };
        
        Matrix X = {
            {1}, // a
            {1}, // e
            {1}, // i
            {1}, // o
            {1}  // u
        };
        
        Matrix A_POW; // A_POW = (A ^ (n - 1)) % MODULO
        matrixBinaryExponentiation(A, n - 1, A_POW, MODULO);
        
        Matrix RES; // RES = (A_POW * X) % MODULO
        matrixMultiplication(A_POW, X, RES, MODULO);
        
        int answer = 0; // answer = (RES[0][0] + RES[1][0] + ... + RES[4][0]) % MODULO
        for(int row = 0; row < (int)RES.size(); ++row){
            answer += RES[row][0];
            answer %= MODULO;
        }
        
        return answer;
    }
};