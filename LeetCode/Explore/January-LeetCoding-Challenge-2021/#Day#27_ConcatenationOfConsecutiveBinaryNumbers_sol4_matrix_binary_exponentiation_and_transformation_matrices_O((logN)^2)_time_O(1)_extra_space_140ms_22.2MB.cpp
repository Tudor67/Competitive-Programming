class Solution {
private:
    const int MODULO = 1e9 + 7;
    using Matrix = vector<vector<int>>;
    
    Matrix getIdentityMatrix(const int& N){
        Matrix I(N, vector<int>(N, 0));
        for(int i = 0; i < N; ++i){
            I[i][i] = 1;
        }
        return I;
    }
    
    Matrix multiply(const Matrix& A, const Matrix& B){
        const int A_ROWS = A.size();
        const int A_COLS = A[0].size();
        const int B_ROWS = B.size();
        const int B_COLS = B[0].size();
        Matrix RES(A_ROWS, vector<int>(B_COLS, 0));
        for(int i = 0; i < A_ROWS; ++i){
            for(int j = 0; j < B_COLS; ++j){
                long long val = 0;
                for(int k = 0; k < A_COLS; ++k){
                    val += 1LL * A[i][k] * B[k][j];
                    val %= MODULO;
                }
                RES[i][j] = (int)val;
            }
        }
        return RES;
    }
    
    Matrix binaryExponentiation(const Matrix& A, int n){
        Matrix RES = getIdentityMatrix((int)A.size());
        Matrix P = A;
        while(n > 0){
            if(n & 1){
                RES = multiply(P, RES);
            }
            P = multiply(P, P);
            n >>= 1;
        }
        return RES;
    }
    
public:
    int concatenatedBinary(int n) {
        Matrix RES = getIdentityMatrix(3);
        n = n - 1;
        int pow = 1;
        int coef = 2;
        while(n > 0){
            pow *= 2;
            coef *= 2;
            if(pow <= n){
                n -= pow;
            }else{
                pow = n;
                n = 0;
            }
            Matrix A = {{coef, 1, 0}, {0, 1, 1}, {0, 0, 1}};
            RES = multiply(binaryExponentiation(A, pow), RES);
        }
        RES = multiply(RES, {{1}, {2}, {1}}); 
        return RES[0][0];
    }
};

/*
        _   _
       |  1  | -> result
n = 1: |  2  | -> n + 1
       |_ 1 _| -> constant
              
        _   _                   _         _     _   _     _   _ 
       |  6  | -> result       |  2^2 1 0  |   |  1  |   |  6  |
n = 2: |  3  | -> n + 1    <=> |   0  1 1  | x |  2  | = |  3  |
       |_ 1 _| -> constant     |_  0  0 1 _|   |_ 1 _|   |_ 1 _|
                                                                
        _   _                   _         _     _         _     _   _     _         _ 2   _   _      _   _ 
       | 27  | -> result       |  2^2 1 0  |   |  2^2 1 0  |   |  1  |   |  2^2 1 0  |   |  1  |    |  27 |
n = 3: |  4  | -> n + 1    <=> |   0  1 1  | x |   0  1 1  | x |  2  | = |   0  1 1  | x |  2  | =  |  4  |
       |_ 1 _| -> constant     |_  0  0 1 _|   |_  0  0 1 _|   |_ 1 _|   |_  0  0 1 _|   |_ 1 _|    |_ 1 _|
       

                      pow = 6       pow = 8         pow = 4         pow = 2   pow = 1
21 = 6 + 8 + 4 + 2 + 1 ------------------------------------------------------------
                        |               |               |               |         |
                        |               |               |               |         |
                        |               |               |               |         |
at current step:        |               |               |               |         |
             coef      pow              |               |               |         |
               |        |               |               |               |         |
               |        |               |               |               |         |
               V        V               V               V               V         V
               
            _         _ 6   _         _ 8   _         _ 4   _         _ 2   _   _ 
           |  2^5 1 0  |   |  2^4 1 0  |   |  2^3 1 0  |   |  2^2 1 0  |   |  1  |
n = 21:    |   0  1 1  | x |   0  1 1  | x |   0  1 1  | x |   0  1 1  | x |  2  |
           |_  0  0 1 _|   |_  0  0 1 _|   |_  0  0 1 _|   |_  0  0 1 _|   |_ 1 _|
*/