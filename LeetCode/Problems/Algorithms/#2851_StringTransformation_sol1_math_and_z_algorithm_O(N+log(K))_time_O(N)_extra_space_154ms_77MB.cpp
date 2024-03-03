class Solution {
private:
    long long fastPow(long long a, long long n, const long long MODULO){
        long long res = 1;
        a %= MODULO;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, const long long MODULO){
        return fastPow(a, MODULO - 2, MODULO);
    }

public:
    int numberOfWays(string s, string t, long long k) {
        const long long N = s.length();
        const long long MODULO = 1e9 + 7;

        const string PS = t + "$" + s + s;
        const int LEN = PS.length();
        vector<int> z(LEN);
        int l = 0;
        int r = 0;
        for(int i = 1; i < LEN; ++i){
            if(i <= r){
                z[i] = min(r - i + 1, z[i - l]);
            }
            while(i + z[i] < LEN && PS[z[i]] == PS[i + z[i]]){
                z[i] += 1;
            }
            if(r < i + z[i] - 1){
                l = i;
                r = i + z[i] - 1;
            }
        }

        long long circularMatchings = count(z.begin(), z.end() - N, N);

        long long a = (fastPow(N - 1, k, MODULO) + fastPow(-1, (k + 1) % 2, MODULO) + MODULO) % MODULO;
        long long b = modInverse(N, MODULO);
        long long res = circularMatchings * a % MODULO * b % MODULO;

        if(s == t){
            res = (res + fastPow(-1, k % 2, MODULO) + MODULO) % MODULO;
        }

        return res;
    }
};