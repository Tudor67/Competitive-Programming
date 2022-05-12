class Hash{
private:
    const int N;
    const int MODULO;
    const int BASE = 131;
    vector<long long> h;
    vector<long long> p;
    
public:
    Hash(const string& S, const int& MODULO): N(S.length()), MODULO(MODULO){
        h.resize(N);
        p.resize(N);
        h[0] = S[0] - 'a' + 1;
        p[0] = 1;
        for(int i = 1; i < N; ++i){
            h[i] = (h[i - 1] * BASE + (S[i] - 'a' + 1)) % MODULO;
            p[i] = (p[i - 1] * BASE) % MODULO;
        }
    }
    
    int getRangeHash(const int& L, const int& R){
        if(L > R){
            return -1;
        }
        if(L == 0){
            return h[R];
        }
        return ((h[R] - h[L - 1] * p[R - L + 1]) % MODULO + MODULO) % MODULO;
    }
};

class Solution {
public:
    long long sumScores(string s) {
        const int N = s.length();
        
        Hash hash1(s, 1e9 + 7);
        Hash hash2(s, 1e9 + 9);
        
        long long res = N;
        for(int i = 1; i < N; ++i){
            if(s[0] != s[i]){
                continue;
            }
            int l = 0;
            int r = N - i;
            while(l != r){
                int mid = (l + r + 1) / 2;
                if(hash1.getRangeHash(0, mid - 1) == hash1.getRangeHash(i, i + mid - 1) &&
                   hash2.getRangeHash(0, mid - 1) == hash2.getRangeHash(i, i + mid - 1)){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            res += r;
        }
        
        return res;
    }
};