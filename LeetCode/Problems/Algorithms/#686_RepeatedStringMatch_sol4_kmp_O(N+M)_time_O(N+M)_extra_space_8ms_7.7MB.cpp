class Solution {
private:
    bool match(const string& S, const string& P){
        const int N = S.length();
        const int M = P.length();
        
        const string PS = P + "$" + S;
        const int L = PS.length();
        
        vector<int> p(L);
        for(int i = 1; i < L; ++i){
            int k = p[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = p[k - 1];
            }
            if(PS[k] == PS[i]){
                p[i] = k + 1;
            }
            if(p[i] == M){
                return true;
            }
        }
        
        return false;
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