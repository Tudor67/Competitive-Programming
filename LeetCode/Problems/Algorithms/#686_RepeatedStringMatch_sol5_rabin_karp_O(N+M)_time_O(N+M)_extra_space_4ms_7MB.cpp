class Solution {
private:
    void mod(long long& a, const long long& MODULO){
        if(a < 0){
            a += MODULO;
        }else if(a >= MODULO){
            a %= MODULO;
        }
    }
    
    bool match(const string& S, const string& P, const long long& BASE, const long long& MODULO){
        const int N = S.length();
        const int M = P.length();
        
        long long pHash = 0;
        for(char c: P){
            pHash *= BASE;
            pHash += (c - 'a' + 1);
            mod(pHash, MODULO);
        }
        
        long long maxBasePow = 1;
        for(int i = 1; i <= M; ++i){
            maxBasePow *= BASE;
            mod(maxBasePow, MODULO);
        }
        
        long long sHash = 0;
        for(int i = 0; i < N; ++i){
            sHash *= BASE;
            sHash += (S[i] - 'a' + 1);
            mod(sHash, MODULO);
            if(i >= M){
                long long oldTerm = maxBasePow * (S[i - M] - 'a' + 1);
                mod(oldTerm, MODULO);
                sHash -= oldTerm;
                mod(sHash, MODULO);
            }
            if(i >= M - 1){
                if(sHash == pHash){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool match(const string& S, const string& P){
        const long long BASE = 131;
        const vector<long long> MODULOS = {(int)(1e9 + 7), (int)(1e9 + 9)};
        for(const long long& MODULO: MODULOS){
            if(!match(S, P, BASE, MODULO)){
                return false;
            }
        }
        return true;
    }
    
    int getCharMask(const string& S){
        int charMask = 0;
        for(char c: S){
            charMask |= (1 << (c - 'a'));
        }
        return charMask;
    }
    
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        string p = b;
        
        int sCharMask = getCharMask(s);
        int pCharMask = getCharMask(p);
        if((sCharMask & pCharMask) != pCharMask){
            return -1;
        }
        
        while(p.length() > s.length()){
            s += a;
        }
        
        int k = ((int)s.length() + (int)a.length() - 1) / (int)a.length();
        
        if(match(s, p)){
            return k;
        }
        
        if(match(s + a, p)){
            return k + 1;
        }
        
        if(match(s + a + a, p)){
            return k + 2;
        }
        
        return -1;
    }
};