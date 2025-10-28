class Solution {
private:
    vector<vector<int>> computeCombinationsModSmallPrime(int prime){
        vector<vector<int>> c(prime, vector<int>(prime));
        for(int i = 0; i < prime; ++i){
            c[i][0] = 1;
            c[i][i] = 1;
            for(int j = 1; j < i; ++j){
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % prime;
            }
        }
        return c;
    }

    int computeCombinationsModPrimeWithLucas(int n, int k, vector<vector<int>>& combModSmallPrime, int prime){
        int res = 1;
        while(n > 0 || k > 0){
            int n_i = n % prime;
            int k_i = k % prime;
            if(k_i > n_i){
                return 0;
            }
            res = res * combModSmallPrime[n_i][k_i] % prime;
            n /= prime;
            k /= prime;
        }
        return res;
    }

    int computeCombinationsMod10(int n, int k, vector<vector<int>>& combMod2, vector<vector<int>>& combMod5,
                                 vector<vector<int>>& crt){
        int mod2 = computeCombinationsModPrimeWithLucas(n, k, combMod2, 2);
        int mod5 = computeCombinationsModPrimeWithLucas(n, k, combMod5, 5);
        return crt[mod2][mod5];
    }

public:
    bool hasSameDigits(string s) {
        const int N = s.length();

        vector<vector<int>> combMod2 = computeCombinationsModSmallPrime(2);
        vector<vector<int>> combMod5 = computeCombinationsModSmallPrime(5);
        vector<vector<int>> crt(2, vector<int>(5));
        for(int i = 0; i < 10; ++i){
            crt[i % 2][i % 5] = i;
        }

        int lRem = 0;
        int rRem = 0;
        for(int i = 0; i < N - 1; ++i){
            lRem = (lRem + computeCombinationsMod10(N - 2, i, combMod2, combMod5, crt) * (s[i] - '0')) % 10;
            rRem = (rRem + computeCombinationsMod10(N - 2, i, combMod2, combMod5, crt) * (s[N - 1 - i] - '0')) % 10;
        }

        return (lRem == rRem);
    }
};