class Solution {
private:
    void mod(long long& a, const long long& MODULO){
        if(a < 0){
            a += MODULO;
        }else if(a >= MODULO){
            a %= MODULO;
        }
    }
    
    void computeHashVectorAndBasePow(const string& S, const long long& BASE, const long long& MODULO,
                                     vector<long long>& h, vector<long long>& basePow){
        const int N = h.size();
        h.assign(N, 0);
        long long currentHash = 0;
        for(int i = 0; i < N; ++i){
            currentHash *= BASE;
            currentHash += (S[i] - 'a' + 1);
            mod(currentHash, MODULO);
            h[i] = currentHash;
        }
        basePow.assign(N, 1);
        for(int i = 1; i < N; ++i){
            basePow[i] = basePow[i - 1] * BASE;
            mod(basePow[i], MODULO);
        }
    }
    
    void updateMatchesPS(vector<long long>& h, vector<long long>& basePow,
                         vector<int>& matchesPS, const int& N, const long long& MODULO){
        for(int i = N - 1; i >= 1; --i){
            int len = N - i;
            long long prefHash = h[len - 1];
            long long preH = h[i - 1] * basePow[N - i];
            mod(preH, MODULO);
            long long suffHash = h[N - 1] - preH;
            mod(suffHash, MODULO);
            if(prefHash == suffHash){
                matchesPS[i] += 1;
            }
        }
    }
    
public:
    string longestPrefix(string s) {
        const int N = s.length();
        const long long BASE = 131;
        const vector<long long> MODULOS = {(int)(1e9 + 7)};
        
        vector<long long> h(N);
        vector<long long> basePow(N);
        vector<int> matchesPS(N);
        for(int i = 0; i < (int)MODULOS.size(); ++i){
            computeHashVectorAndBasePow(s, BASE, MODULOS[i], h, basePow);
            updateMatchesPS(h, basePow, matchesPS, N, MODULOS[i]);
        }
        
        int maxPrefSuffLen = 0;
        for(int i = 0; i < N; ++i){
            int len = N - i;
            if(matchesPS[i] == (int)MODULOS.size() && len > maxPrefSuffLen){
                maxPrefSuffLen = len;
            }
        }
        
        return s.substr(0, maxPrefSuffLen);
    }
};