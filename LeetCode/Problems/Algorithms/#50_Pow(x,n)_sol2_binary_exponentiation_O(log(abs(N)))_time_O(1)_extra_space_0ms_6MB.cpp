class Solution {
private:
    double binaryExponentiation(double a, int n){
        double res = 1;
        while(n > 0){
            if(n & 1){
                res *= a;
            }
            n >>= 1;
            if(n > 0){
                a *= a;
            }
        }
        return res;
    }

public:
    double myPow(double x, int n) {
        if(n == INT_MIN){
            n = INT_MIN + 2;
        }
        if(n < 0){
            x = 1.0 / x;
            n = -n;
        }
        return binaryExponentiation(x, n);
    }
};