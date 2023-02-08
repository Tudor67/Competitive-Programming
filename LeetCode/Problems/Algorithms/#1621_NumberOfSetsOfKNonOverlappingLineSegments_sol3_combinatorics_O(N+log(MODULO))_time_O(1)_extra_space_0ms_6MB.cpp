class Solution {
private:
    long long fastPow(long long a, long long n, const long long& MODULO){
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, const long long& MODULO){
        return fastPow(a, MODULO - 2, MODULO);
    }

    long long factorial(long long n, const long long& MODULO){
        long long f = 1;
        for(long long i = 2; i <= n; ++i){
            f = (f * i) % MODULO;
        }
        return f;
    }

    long long nCk(long long n, long long k, const long long& MODULO){
        long long nFactorial = factorial(n, MODULO);
        long long kFactorial = factorial(k, MODULO);
        long long nkDiffFactorial = factorial(n - k, MODULO);

        long long kFactorialInv = modInverse(kFactorial, MODULO);
        long long nkDiffFactorialInv = modInverse(nkDiffFactorial, MODULO);

        return ((nFactorial * kFactorialInv % MODULO) * nkDiffFactorialInv) % MODULO;
    }

public:
    int numberOfSets(int n, int k) {
        const long long MODULO = 1e9 + 7;
        return nCk(n + k - 1, 2 * k, MODULO);
    }
};

/*
* We reduce the initial problem (where the segments can share the endpoints) to
  a simpler problem (where the segments cannot share the endpoints);

* Drawing k non-overlapping segments (which can share the endpoints) from points [0 .. x]
  is the same as
  Drawing k non-overlapping segments (which cannot share the endpoints) from points [0 .. x + k - 1];

* We can draw k non-overlapping segments (which cannot share the endpoints) from points [0 .. (n - 1) + k - 1]
  in nCk(n + k - 1, 2 * k) ways;

* Three segments (which can share the endpoints) {[0, 5], [5, 8], [8, 14]}
  can be represented by the following
  Three segments (which cannot share the endpoints) {[0, 5], [6, 9], [10, 16]};
* For k segments we simply shift to the right all (k - 1) segments (we don't include the first segment)
  to avoid sharing of the endpoints;
*/