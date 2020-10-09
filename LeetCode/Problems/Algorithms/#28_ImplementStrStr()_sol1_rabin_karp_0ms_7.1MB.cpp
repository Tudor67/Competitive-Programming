class Solution {
private:
    const int MODULO = 666013;
    const int BASE = 128;
    
    int pow(const int& A, const int& N){
        int p = 1;
        for(int i = 1; i <= N; ++i){
            p = (p * A) % MODULO;
        }
        return p;
    }
    
    int getHash(const string& S, int startPos, int endPos){
        int hash = 0;
        for(int i = startPos; i < endPos; ++i){
            hash = (hash * BASE + S[i]) % MODULO;
        }
        return hash;
    }
    
    bool match(const string& S1, int pos, const string& S2){
        for(int i = 0; i < S2.length(); ++i){
            if(S1[i + pos] != S2[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }
        
        if(haystack.length() < needle.length()){
            return -1;
        }

        const int MAX_P = pow(BASE, (int)needle.length() - 1);        
        int haystackHash = 0;
        int needleHash = getHash(needle, 0, needle.length());
        for(int i = 0; i < haystack.length(); ++i){
            if(i >= needle.length()){
                haystackHash = ((haystackHash - MAX_P * haystack[i - (int)needle.length()]) % MODULO + MODULO) % MODULO;
            }
            haystackHash = (1LL * haystackHash * BASE + haystack[i]) % MODULO;
            if(i >= (int)needle.length() - 1 && haystackHash == needleHash && match(haystack, i - (int)needle.length() + 1, needle)){
                return i - (int)needle.length() + 1;
            }
        }
        
        return -1;
    }
};