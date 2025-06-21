class Solution {
private:
    long long fastPow(long long a, long long n, const long long MODULO){
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = res * a % MODULO;
            }
            a = a * a % MODULO;
            n >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, const long long MODULO){
        return fastPow(a, MODULO - 2, MODULO);
    }

    long long factorial(long long n, const long long MODULO){
        long long res = 1;
        for(long long i = 1; i <= n; ++i){
            res = res * i % MODULO;
        }
        return res;
    }

    long long nCk(long long n, long long k, const long long MODULO){
        return factorial(n, MODULO) *
               modInverse(factorial(k, MODULO) * factorial(n - k, MODULO) % MODULO, MODULO) % MODULO;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        const long long MODULO = 1'000'000'007;
        return m * fastPow(m - 1, n - 1 - k, MODULO) % MODULO *
               nCk(n - 1, k, MODULO) % MODULO;
    }
};