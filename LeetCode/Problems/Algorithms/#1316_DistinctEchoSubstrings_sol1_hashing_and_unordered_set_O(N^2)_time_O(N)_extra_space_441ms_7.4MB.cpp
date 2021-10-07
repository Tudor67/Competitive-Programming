class Solution {
private:
    long long modInverse(long long a, const long long& MODULO){
        a %= MODULO;
        long long n = MODULO - 2;
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n /= 2;
        }
        return res;
    }
    
    long long getRangeHash(int l, int r, vector<long long>& prefHash, long long invPow, const long long& MODULO){
        long long rangeHash = prefHash[r];
        if(l > 0){
            rangeHash -= prefHash[l - 1];
            rangeHash += MODULO;
            rangeHash %= MODULO;
        }
        rangeHash *= invPow;
        rangeHash %= MODULO;
        return rangeHash;
    }
    
public:
    int distinctEchoSubstrings(string text) {
        const int N = text.length();
        const long long BASE = 131;
        const long long MODULO = 1e9 + 7;
        
        vector<long long> prefHash(N);
        prefHash[0] = text[0] - 'a' + 1;
        long long p = BASE;
        for(int i = 1; i < N; ++i){
            prefHash[i] = (prefHash[i - 1] + p * (text[i] - 'a' + 1)) % MODULO;
            p = (p * BASE) % MODULO;
        }
        
        vector<long long> invPow(N);
        invPow[0] = 1;
        long long invBase = modInverse(BASE, MODULO);
        for(int i = 1; i < N; ++i){
            invPow[i] = (invPow[i - 1] * invBase) % MODULO;
        }
        
        unordered_set<int> hashesSet;
        for(int i = 0; i < N; i += 1){
            for(int j = i + 1; j < N; j += 2){
                int length = (j - i + 1);
                long long aHash = getRangeHash(i, i + length / 2 - 1, prefHash, invPow[i], MODULO);
                long long bHash = getRangeHash(i + length / 2, j, prefHash, invPow[i + length / 2], MODULO);
                if(aHash == bHash){
                    hashesSet.insert(aHash);
                }
            }
        }
        
        return hashesSet.size();
    }
};