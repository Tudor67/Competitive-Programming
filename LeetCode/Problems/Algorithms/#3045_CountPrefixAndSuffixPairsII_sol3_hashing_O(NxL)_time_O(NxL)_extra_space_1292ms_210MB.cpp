class RollingHash{
private:
    const long long BASE;
    const long long MODULO;
    vector<long long> h;
    vector<long long> p;
    
public:
    RollingHash(const long long BASE, const long long MODULO): BASE(BASE), MODULO(MODULO){
        
    }
    
    void reset(const string& S){
        const int N = S.length();
        h.resize(N);
        p.resize(N);
        
        h[0] = S[0];
        p[0] = 1;
        for(int i = 1; i < N; ++i){
            h[i] = (h[i - 1] * BASE + S[i]) % MODULO;
            p[i] = (p[i - 1] * BASE) % MODULO;
        }
    }
    
    long long getHash(const int L, const int R){
        if(L > R){
            return -1;
        }
        if(L == 0){
            return h[R];
        }
        return (h[R] - h[L - 1] * p[R - (L - 1)] % MODULO + MODULO) % MODULO;
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        const long long BASE = 131;
        const long long MODULO1 = 1'000'000'007;
        const long long MODULO2 = 1'000'000'009;
        
        long long res = 0;
        unordered_map<string, int> freq;
        RollingHash rh1(BASE, MODULO1);
        RollingHash rh2(BASE, MODULO2);
        
        for(const string& WORD: words){
            rh1.reset(WORD);
            rh2.reset(WORD);
            
            const int WORD_LEN = WORD.length();
            for(int i = 0; i < WORD_LEN; ++i){
                int prefixHash1 = rh1.getHash(0, i);
                int suffixHash1 = rh1.getHash(WORD_LEN - 1 - i, WORD_LEN - 1);
                int prefixHash2 = rh2.getHash(0, i);
                int suffixHash2 = rh2.getHash(WORD_LEN - 1 - i, WORD_LEN - 1);
                
                if(prefixHash1 == suffixHash1 && prefixHash2 == suffixHash2){
                    string hashStr = to_string(prefixHash1) + "$" + to_string(prefixHash2);
                    if(freq.count(hashStr)){
                        res += freq[hashStr];
                    }
                }
            }
            
            freq[to_string(rh1.getHash(0, WORD_LEN - 1)) + "$" + to_string(rh2.getHash(0, WORD_LEN - 1))] += 1;
        }
        
        return res;
    }
};