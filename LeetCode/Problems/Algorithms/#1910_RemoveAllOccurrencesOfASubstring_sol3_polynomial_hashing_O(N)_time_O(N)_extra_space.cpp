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
        vector<ll> basePow(N + 1);
        basePow[0] = 1;
        for(int i = 1; i < N; ++i){
            basePow[i] = (basePow[i - 1] * BASE) % MODULO;
        }
        
        ll pHash = part[0] - 'a' + 1;
        for(int i = 1; i < P; ++i){
            pHash = (pHash * BASE + (part[i] - 'a' + 1)) % MODULO;
        }
        
        // currentStr hashing
        string currentStr;
        vector<ll> h(N);
        
        for(char c: s){
            currentStr.push_back(c);
            int i = (int)currentStr.size() - 1;
            
            if(i == 0){
                h[i] = currentStr[i] - 'a' + 1;
            }else{
                h[i] = (h[i - 1] * BASE + (currentStr[i] - 'a' + 1)) % MODULO;
            }
            
            ll strHash = -1;
            if(i >= P - 1){
                if(i - P >= 0){
                    strHash = (h[i] - (h[i - P] * basePow[P]) % MODULO + MODULO) % MODULO;
                }else{
                    strHash = h[i];
                }
            }
            
            if(pHash == strHash){
                currentStr.resize((int)currentStr.size() - P);
            }
        }
        
        return currentStr;
    }
};