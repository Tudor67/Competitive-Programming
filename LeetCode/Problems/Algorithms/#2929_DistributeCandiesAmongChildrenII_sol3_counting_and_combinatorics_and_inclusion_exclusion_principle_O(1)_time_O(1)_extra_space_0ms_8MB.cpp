class Solution {
private:
    long long nCk(long long n, long long k){
        if(n < k){
            return 0;
        }

        long long res = 1;
        for(long long i = 1; i <= k; ++i){
            res *= (n - k + i);
            res /= i;
        }

        return res;
    }

public:
    long long distributeCandies(int n, int limit) {
        limit = min(limit, n);

        long long w1 = nCk(n + 2 - (limit + 1), 2);
        long long w2 = nCk(n + 2 - (limit + 1), 2);
        long long w3 = nCk(n + 2 - (limit + 1), 2);
        long long w12 = nCk(n + 2 - 2 * (limit + 1), 2);
        long long w13 = nCk(n + 2 - 2 * (limit + 1), 2);
        long long w23 = nCk(n + 2 - 2 * (limit + 1), 2);
        long long w123 = nCk(n + 2 - 3 * (limit + 1), 2);
        long long badWays = w1 + w2 + w3 - w12 - w13 - w23 + w123;
        long long totalWays = nCk(n + 2, 2);

        return totalWays - badWays;
    }
};