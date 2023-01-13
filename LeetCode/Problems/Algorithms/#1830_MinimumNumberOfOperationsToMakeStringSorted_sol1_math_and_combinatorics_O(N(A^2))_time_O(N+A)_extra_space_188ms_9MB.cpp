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
        vector<int> count(100 + A);
        for(int i = N - 1; i >= 0; --i){
            count[s[i]] += 1;
            for(char currentChar = s[i] - 1; currentChar >= 'a'; --currentChar){
                if(count[currentChar] >= 1){
                    count[currentChar] -= 1;

                    long long contrib = f[N - 1 - i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        contrib = (contrib * fInv[count[c]]) % MODULO;
                    }
                    res = (res + contrib) % MODULO;

                    count[currentChar] += 1;
                }
            }
        }

        return res;
    }
};