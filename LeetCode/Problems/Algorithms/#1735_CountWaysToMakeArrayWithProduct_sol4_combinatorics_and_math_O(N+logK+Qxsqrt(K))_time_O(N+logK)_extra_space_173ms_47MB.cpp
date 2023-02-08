class Solution {
private:
    long long nCk(int n, int k, vector<long long>& f, vector<long long>& fInv, const int& MODULO){
        return (((f[n] * fInv[n - k]) % MODULO) * fInv[k]) % MODULO;
    }

    int solve(int n, int k, vector<long long>& f, vector<long long>& fInv, const int& MODULO){
        long long res = 1;
        for(int i = 2; i * i <= k; ++i){
            int primePow = 0;
            while(k % i == 0){
                k /= i;
                primePow += 1;
            }
            res = (res * nCk(n - 1 + primePow, n - 1, f, fInv, MODULO)) % MODULO;
        }
        if(k > 1){
            res = (res * n) % MODULO;
        }
        return res;
    }

public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        const int Q = queries.size();
        const int MODULO = 1e9 + 7;
        const int N = 1e4;
        const int K = 1e4;
        const int LIMIT = N + log2(K) + 5;

        vector<long long> inv(LIMIT + 1, 1);
        vector<long long> f(LIMIT + 1, 1);
        vector<long long> fInv(LIMIT + 1, 1);
        for(int i = 2; i <= LIMIT; ++i){
            inv[i] = MODULO - ((MODULO / i) * inv[MODULO % i] % MODULO);
            f[i] = (f[i - 1] * i) % MODULO;
            fInv[i] = (fInv[i - 1] * inv[i]) % MODULO;
        }

        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int n = queries[i][0];
            int k = queries[i][1];
            answer[i] = solve(n, k, f, fInv, MODULO);
        }

        return answer;
    }
};