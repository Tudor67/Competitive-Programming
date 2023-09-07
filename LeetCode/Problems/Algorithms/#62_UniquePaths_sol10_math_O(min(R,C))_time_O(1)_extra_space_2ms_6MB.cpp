class Solution {
private:
    long long nCk(long long n, long long k){
        long long res = 1;
        for(long long i = 1; i <= k; ++i){
            res *= (n - k + i);
            res /= i;
        }
        return res;
    }

public:
    int uniquePaths(int m, int n) {
        return nCk(m + n - 2, min(m, n) - 1);
    }
};