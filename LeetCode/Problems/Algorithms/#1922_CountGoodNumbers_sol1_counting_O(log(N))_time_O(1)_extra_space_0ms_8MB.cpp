class Solution {
private:
    long long fastPow(long long a, long long n, const long long MODULO){
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            n >>= 1;
            a = (a * a) % MODULO;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        const long long MODULO = 1'000'000'007;
        long long even = (n + 1) / 2;
        long long odd = n - even;
        return fastPow(5, even, MODULO) * fastPow(4, odd, MODULO) % MODULO;
    }
};