class Solution {
private:
    using ll = long long;
    const ll BASE = 131;
    const ll MODULO = 1e9 + 7;
    
    ll modInverse(ll a){
        ll n = MODULO - 2;
        ll res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n >>= 1;
        }
        return res;
    }
    
    ll getRangeHash(const int& L, const int& R, const vector<ll>& PREF_HASHES, const ll& NORM_POW){
        ll rangeHash = PREF_HASHES[R];
        if(L > 0){
            rangeHash -= PREF_HASHES[L - 1];
            rangeHash += MODULO;
            rangeHash %= MODULO;
        }
        rangeHash *= NORM_POW;
        rangeHash %= MODULO;
        return rangeHash;
    }
    
public:
    string removeOccurrences(string s, string part) {
        const int N = s.length();
        const int P = part.length();
        
        if(N < P){
            return s;
        }
        
        // p hashing
        vector<ll> basePow(N + 1);
        basePow[0] = 1;
        for(int i = 1; i < N; ++i){
            basePow[i] = (basePow[i - 1] * BASE) % MODULO;
        }
        
        vector<ll> basePowInv(N + 1);
        basePowInv[0] = 1;
        basePowInv[1] = modInverse(BASE);
        for(int i = 2; i < N; ++i){
            basePowInv[i] = (basePowInv[i - 1] * basePowInv[1]) % MODULO;
        }
        
        ll pHash = part[0] - 'a' + 1;
        for(int i = 1; i < P; ++i){
            pHash += basePow[i] * (part[i] - 'a' + 1);
            pHash %= MODULO;
        }
        
        // currentStr hashing
        string currentStr;
        vector<ll> prefHashStr(N);
        
        for(char c: s){
            currentStr.push_back(c);
            int i = (int)currentStr.size() - 1;
            
            if(i == 0){
                prefHashStr[i] = currentStr[i] - 'a' + 1;
            }else{
                prefHashStr[i] = (prefHashStr[i - 1] + basePow[i] * (currentStr[i] - 'a' + 1)) % MODULO;
            }
            
            ll strHash = -1;
            if(P - 1 <= i){
                strHash = getRangeHash(i - P + 1, i, prefHashStr, basePowInv[i - P + 1]);
            }
            
            if(pHash == strHash){
                currentStr.resize((int)currentStr.size() - P);
            }
        }
        
        return currentStr;
    }
};