class Solution {
public:
    int idealArrays(int n, int maxVal) {
        const int LOG_MAX_VAL = log2(maxVal + 10);
        const long long MODULO = 1'000'000'007;

        vector<int> maxPrimeOf(maxVal + 1);
        iota(maxPrimeOf.begin(), maxPrimeOf.end(), 0);

        for(int i = 2; i <= maxVal; ++i){
            if(maxPrimeOf[i] == i){
                for(int j = i + i; j <= maxVal; j += i){
                    maxPrimeOf[j] = i;
                }
            }
        }

        vector<vector<long long>> comb(n + LOG_MAX_VAL + 1, vector<long long>(LOG_MAX_VAL + 1));
        for(int i = 0; i < (int)comb.size(); ++i){
            comb[i][0] = 1;
            for(int j = 1; j <= min(i, (int)comb[i].size() - 1); ++j){
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MODULO;
            }
        }

        long long res = 0;
        for(int val = 1; val <= maxVal; ++val){
            int x = val;
            long long contrib = 1;
            while(x > 1){
                int prime = maxPrimeOf[x];
                int primeFreq = 0;
                while(x % prime == 0){
                    primeFreq += 1;
                    x /= prime;
                }
                contrib *= comb[n - 1 + primeFreq][primeFreq];
                contrib %= MODULO;
            }
            res += contrib;
            res %= MODULO;
        }

        return res;
    }
};