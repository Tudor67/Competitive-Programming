class Solution {
private:
    long long getRangeHash(int l, int r, vector<long long>& h, vector<long long>& p, const long long& MODULO){
        long long rangeHash = h[r];
        if(l > 0){
            rangeHash = ((h[r] - (h[l - 1] * p[r - l + 1]) % MODULO) + MODULO) % MODULO;
        }
        return rangeHash;
    }
    
public:
    int distinctEchoSubstrings(string text) {
        const int N = text.length();
        const long long BASE = 131;
        const long long MODULO = 1e9 + 7;
        
        vector<long long> h(N);
        vector<long long> p(N);
        h[0] = text[0] - 'a' + 1;
        p[0] = 1;
        for(int i = 1; i < N; ++i){
            h[i] = (h[i - 1] * BASE + (text[i] - 'a' + 1)) % MODULO;
            p[i] = (p[i - 1] * BASE) % MODULO;
        }
        
        unordered_set<int> hashesSet;
        for(int i = 0; i < N; i += 1){
            for(int j = i + 1; j < N; j += 2){
                int length = (j - i + 1);
                long long aHash = getRangeHash(i, i + length / 2 - 1, h, p, MODULO);
                long long bHash = getRangeHash(i + length / 2, j, h, p, MODULO);
                if(aHash == bHash){
                    hashesSet.insert(aHash);
                }
            }
        }
        
        return hashesSet.size();
    }
};