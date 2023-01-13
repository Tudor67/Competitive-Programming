class Solution {
public:
    int makeStringSorted(string s) {
        const int N = s.length();
        const int A = 26;
        const int MODULO = 1e9 + 7;

        vector<long long> inv(N + 1, 1);
        vector<long long> f(N + 1, 1);
        vector<long long> fInv(N + 1, 1);
        for(int i = 2; i <= N; ++i){
            inv[i] = MODULO - ((MODULO / i) * inv[MODULO % i] % MODULO);
            f[i] = (f[i - 1] * i) % MODULO;
            fInv[i] = (fInv[i - 1] * inv[i]) % MODULO;
        }

        long long res = 0;
        long long contrib = 1;
        vector<int> count(100 + A);
        for(int i = N - 1; i >= 0; --i){
            contrib = (contrib * f[N - 1 - i]) % MODULO;

            contrib = (contrib * f[count[s[i]]]) % MODULO;
            count[s[i]] += 1;
            contrib = (contrib * fInv[count[s[i]]]) % MODULO;
            
            for(char currentChar = s[i] - 1; currentChar >= 'a'; --currentChar){
                if(count[currentChar] >= 1){
                    contrib = (contrib * f[count[currentChar]]) % MODULO;
                    count[currentChar] -= 1;
                    contrib = (contrib * fInv[count[currentChar]]) % MODULO;
                    
                    res = (res + contrib) % MODULO;

                    contrib = (contrib * f[count[currentChar]]) % MODULO;
                    count[currentChar] += 1;
                    contrib = (contrib * fInv[count[currentChar]]) % MODULO;
                }
            }

            contrib = (contrib * fInv[N - 1 - i]) % MODULO;
        }

        return res;
    }
};