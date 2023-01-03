class Solution {
private:
    long long fastPow(long long a, long long n, const long long& MODULO){
        long long res = 1;
        while(n > 0){
            if(n % 2 == 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n /= 2;
        }
        return res;
    }
    
    long long modInverse(long long a, const long long& MODULO){
        return fastPow(a, MODULO - 2, MODULO);
    }
    
public:
    int countAnagrams(string s) {
        const int N = s.length();
        const long long MODULO = 1e9 + 7;
        
        vector<long long> f(N + 1, 1);
        for(int i = 2; i <= N; ++i){
            f[i] = (f[i - 1] * i) % MODULO;
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
                contrib = (contrib * modInverse(f[charCount], MODULO)) % MODULO;
            }
            
            res = (res * contrib) % MODULO;
        }
        
        return res;
    }
};