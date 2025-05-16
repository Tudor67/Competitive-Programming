class Solution {
private:
    using Matrix2D = vector<vector<int>>;
    const int MODULO = 1'000'000'007;
    const int ALPHABET_SIZE = 26;

    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, const int MODULO, Matrix2D& RES){
        if(A.size() != RES.size() || B[0].size() != RES[0].size()){
            RES.assign(A.size(), vector<int>(B[0].size()));
        }
        
        const int RES_ROWS = RES.size();
        const int RES_COLS = RES[0].size();

        Matrix2D TEMP(RES_ROWS, vector<int>(RES_COLS));
        for(int i = 0; i < RES_ROWS; ++i){
            for(int j = 0; j < RES_COLS; ++j){
                for(int k = 0; k < (int)A[0].size(); ++k){
                    TEMP[i][j] = (TEMP[i][j] + (long long)A[i][k] * (long long)B[k][j]) % MODULO;
                }
            }
        }

        RES = TEMP;
    }

    void matrixBinaryExponentiation(Matrix2D A, int n, const int MODULO, Matrix2D& RES){
        assert(A[0].size() == A.size());

        RES.assign(A.size(), vector<int>(A.size()));
        for(int i = 0; i < (int)RES.size(); ++i){
            RES[i][i] = 1;
        }

        while(n > 0){
            if(n & 1){
                matrixMultiplication(RES, A, MODULO, RES);
            }
            matrixMultiplication(A, A, MODULO, A);
            n >>= 1;
        }
    }

public:
    int lengthAfterTransformations(string s, int t) {
        Matrix2D A(ALPHABET_SIZE, vector<int>(ALPHABET_SIZE));
        for(int i = 0; i + 1 < ALPHABET_SIZE; ++i){
            A[i][i + 1] = 1;
        }
        A[ALPHABET_SIZE - 1][0] = 1;
        A[ALPHABET_SIZE - 1][1] = 1;

        Matrix2D A_POW_T;
        matrixBinaryExponentiation(A, t, MODULO, A_POW_T);

        Matrix2D freq(1, vector<int>(ALPHABET_SIZE));
        for(char c: s){
            freq[0][c - 'a'] += 1;
        }

        Matrix2D RES;
        matrixMultiplication(freq, A_POW_T, MODULO, RES);

        return accumulate(RES[0].begin(), RES[0].end(), (long long)0) % MODULO;
    }
};