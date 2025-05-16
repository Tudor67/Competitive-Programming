class Solution {
private:
    using Matrix2D = vector<vector<int>>;
    const int ALPHABET_SIZE = 26;
    const int MODULO = 1'000'000'007;

    void matrixMultiplication(const Matrix2D& A, const Matrix2D& B, const int MODULO, Matrix2D& RES){
        assert(A[0].size() == B.size());

        const int RES_ROWS = A.size();
        const int RES_COLS = B[0].size();

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
        assert(A.size() == A[0].size());

        RES.assign(A.size(), vector<int>(A.size()));
        for(int i = 0; i < (int)A.size(); ++i){
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
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix2D A(ALPHABET_SIZE, vector<int>(ALPHABET_SIZE));
        for(int i = 0; i < ALPHABET_SIZE; ++i){
            for(int j = i + 1; j <= i + nums[i]; ++j){
                A[i][j % ALPHABET_SIZE] = 1;
            }
        }

        Matrix2D A_POW_T;
        matrixBinaryExponentiation(A, t, MODULO, A_POW_T);

        Matrix2D FREQ(1, vector<int>(ALPHABET_SIZE));
        for(char c: s){
            FREQ[0][c - 'a'] += 1;
        }

        Matrix2D RES;
        matrixMultiplication(FREQ, A_POW_T, MODULO, RES);

        return accumulate(RES[0].begin(), RES[0].end(), (long long)0) % MODULO;
    }
};