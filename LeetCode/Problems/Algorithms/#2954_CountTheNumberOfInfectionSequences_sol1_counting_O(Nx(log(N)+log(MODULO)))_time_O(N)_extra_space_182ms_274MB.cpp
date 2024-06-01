class Solution {
private:
    const long long MODULO = 1e9 + 7;

    long long fastPow(long long a, long long n){
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n /= 2;
        }
        return res;
    }

    long long modInverse(long long a){
        return fastPow(a, MODULO - 2);
    }

    long long nCk(long long n, long long k, vector<long long>& factorial){
        return factorial[n] *
               modInverse(factorial[n - k]) % MODULO *
               modInverse(factorial[k]) % MODULO;
    }

public:
    int numberOfSequence(int n, vector<int>& sick) {
        vector<long long> factorial(n + 1, 1);
        for(int i = 1; i <= n; ++i){
            factorial[i] = factorial[i - 1] * i % MODULO;
        }

        long long res = 1;
        long long totalLen = 0;
        for(int i = 1; i < (int)sick.size(); ++i){
            long long len = sick[i] - sick[i - 1] - 1;
            totalLen += len;
            res = res * fastPow(2, len - 1) % MODULO;
            res = res * nCk(totalLen, len, factorial) % MODULO;
        }

        if(0 < sick[0]){
            long long len = sick.front();
            totalLen += len;
            res = res * nCk(totalLen, len, factorial) % MODULO;
        }

        if(sick.back() < n - 1){
            long long len = n - 1 - sick.back();
            totalLen += len;
            res = res * nCk(totalLen, len, factorial) % MODULO;
        }

        return res;
    }
};