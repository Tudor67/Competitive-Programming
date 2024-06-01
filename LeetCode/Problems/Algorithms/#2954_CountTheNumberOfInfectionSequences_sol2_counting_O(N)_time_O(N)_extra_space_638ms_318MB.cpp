class Solution {
private:
    const long long MODULO = 1e9 + 7;

    long long nCk(long long n, long long k, vector<long long>& factorial, vector<long long>& factorialInv){
        return factorial[n] *
               factorialInv[n - k] % MODULO *
               factorialInv[k] % MODULO;
    }

public:
    int numberOfSequence(int n, vector<int>& sick) {
        vector<long long> factorial(n + 1, 1);
        vector<long long> factorialInv(n + 1, 1);
        vector<long long> inv(n + 1, 1);
        vector<long long> pow2(n + 1, 1);
        pow2[1] = 2;
        for(int i = 2; i <= n; ++i){
            inv[i] = MODULO - (MODULO / i) * inv[MODULO % i] % MODULO;
            factorial[i] = factorial[i - 1] * i % MODULO;
            factorialInv[i] = factorialInv[i - 1] * inv[i] % MODULO;
            pow2[i] = pow2[i - 1] * 2 % MODULO;
        }

        long long res = 1;
        long long totalLen = 0;
        for(int i = 1; i < (int)sick.size(); ++i){
            long long len = sick[i] - sick[i - 1] - 1;
            totalLen += len;
            res = res * pow2[max(0LL, len - 1)] % MODULO;
            res = res * nCk(totalLen, len, factorial, factorialInv) % MODULO;
        }

        if(0 < sick[0]){
            long long len = sick.front();
            totalLen += len;
            res = res * nCk(totalLen, len, factorial, factorialInv) % MODULO;
        }

        if(sick.back() < n - 1){
            long long len = n - 1 - sick.back();
            totalLen += len;
            res = res * nCk(totalLen, len, factorial, factorialInv) % MODULO;
        }

        return res;
    }
};