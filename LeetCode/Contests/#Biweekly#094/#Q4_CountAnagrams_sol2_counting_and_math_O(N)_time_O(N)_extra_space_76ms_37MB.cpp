class Solution {
public:
    int countAnagrams(string s) {
        const int N = s.length();
        const long long MODULO = 1e9 + 7;
        
        vector<long long> f(N + 1, 1);
        vector<long long> fInv(N + 1, 1);
        vector<long long> inv(N + 1, 1);
        for(int i = 2; i <= N; ++i){
            inv[i] = MODULO - ((MODULO / i) * inv[MODULO % i] % MODULO);
            f[i] = (f[i - 1] * i) % MODULO;
            fInv[i] = (fInv[i - 1] * inv[i]) % MODULO;
        }
        
        long long res = 1;
        istringstream iss(s);
        string currentWord;
        unordered_map<char, int> count;
        while(iss >> currentWord){
            count.clear();
            for(char c: currentWord){
                count[c] += 1;
            }
            
            long long n = currentWord.length();
            long long contrib = f[n];
            for(const pair<char, int>& P: count){
                long long charCount = P.second;
                contrib = (contrib * fInv[charCount]) % MODULO;
            }
            
            res = (res * contrib) % MODULO;
        }
        
        return res;
    }
};