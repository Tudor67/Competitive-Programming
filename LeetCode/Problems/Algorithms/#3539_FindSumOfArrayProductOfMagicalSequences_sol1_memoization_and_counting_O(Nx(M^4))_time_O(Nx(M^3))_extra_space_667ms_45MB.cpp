class Solution {
private:
    const long long MODULO = 1'000'000'007;
    vector<long long> factorialCache = {1};

    long long factorial(long long n){
        while(n >= (int)factorialCache.size()){
            factorialCache.push_back(factorialCache.back() * (long long)factorialCache.size() % MODULO);
        }
        return factorialCache[n];
    }

    long long fastPow(long long a, long long n){
        a %= MODULO;
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

    long long modInverse(long long a){
        return fastPow(a, MODULO - 2);
    }

    long long nCk(long long n, long long k){
        return factorial(n) *
               modInverse(factorial(n - k) * factorial(k) % MODULO) % MODULO;
    }

    long long f(int i, int m, int k, unsigned int mask, vector<int>& nums, unordered_map<int, int>& memo){
        if(m == 0){
            return (int)(k == popcount(mask));
        }

        if(i == (int)nums.size()){
            return 0;
        }

        int state = i | (m << 6) | (k << 11) | (mask << 16);
        if(memo.count(state)){
            return memo[state];
        }

        long long res = 0;
        for(int cnt = 0; cnt <= m; ++cnt){
            res += nCk(m, cnt) *
                   fastPow(nums[i], cnt) % MODULO *
                   f(i + 1, m - cnt, k - ((mask + cnt) & 1), (mask + cnt) >> 1, nums, memo) % MODULO;
            res %= MODULO;
        }

        memo[state] = res;
        return res;
    }

public:
    int magicalSum(int m, int k, vector<int>& nums) {
        unordered_map<int, int> memo;
        return f(0, m, k, 0, nums, memo);
    }
};