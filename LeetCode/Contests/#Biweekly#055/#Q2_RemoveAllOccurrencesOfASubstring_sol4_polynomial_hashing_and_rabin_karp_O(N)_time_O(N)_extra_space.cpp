class Solution {
private:
    using ll = long long;
    const ll BASE = 131;
    const ll MODULO = 1e9 + 7;
    
public:
    string removeOccurrences(string s, string part) {
        const int N = s.length();
        const int P = part.length();
        
        if(N < P){
            return s;
        }
        
        // p hashing
        ll maxBasePow = 1;
        for(int i = 1; i <= P; ++i){
            maxBasePow = (maxBasePow * BASE) % MODULO;
        }
        
        ll pHash = 0;
        for(int i = 0; i < P; ++i){
            pHash = (pHash * BASE + (part[i] - 'a' + 1)) % MODULO;
        }
        
        // currentStr hashing
        string currentStr;
        vector<ll> strHash(N);
        
        for(char c: s){
            currentStr.push_back(c);
            int i = (int)currentStr.size() - 1;
            
            if(i == 0){
                strHash[i] = currentStr[i] - 'a' + 1;
            }else{
                strHash[i] = (strHash[i - 1] * BASE + (currentStr[i] - 'a' + 1)) % MODULO;
                if(P <= i){
                    strHash[i] -= (maxBasePow * (currentStr[i - P] - 'a' + 1)) % MODULO;
                    strHash[i] += MODULO;
                    strHash[i] %= MODULO;
                }
            }
            
            if(pHash == strHash[i]){
                currentStr.resize((int)currentStr.size() - P);
            }
        }
        
        return currentStr;
    }
};