class RollingHash{
private:
    const long long BASE;
    const long long MODULO;
    vector<long long> h;
    vector<long long> p;
    
public:
    RollingHash(const string& S, const long long& BASE, const long long& MODULO): BASE(BASE), MODULO(MODULO){
        const int N = S.length();
        h.resize(N);
        p.resize(N);
        h[0] = S[0];
        p[0] = 1;
        for(int i = 1; i < N; ++i){
            h[i] = (h[i - 1] * BASE + S[i]) % MODULO;
            p[i] = (p[i - 1] * BASE) % MODULO;
        }
    }
    
    long long getRangeHash(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        if(L == 0){
            return h[R];
        }
        return (h[R] - ((h[L - 1] * p[R - L + 1]) % MODULO) + MODULO) % MODULO;
    }
};

class Solution {
private:
    const int INF = 1e9;
    
    int maxOperations(RollingHash& hash1, RollingHash& hash2, int startPos, const int& N, vector<int>& memo) {
        if(N - startPos <= 1){
            return N - startPos;
        }
        
        if(memo[startPos] != INF){
            return memo[startPos];
        }
        
        int res = 1;
        for(int len = 1; startPos + 2 * len - 1 < N; ++len){
            if(hash1.getRangeHash(startPos, startPos + len - 1) == hash1.getRangeHash(startPos + len, startPos + 2 * len - 1) &&
               hash2.getRangeHash(startPos, startPos + len - 1) == hash2.getRangeHash(startPos + len, startPos + 2 * len - 1)){
                res = max(res, 1 + maxOperations(hash1, hash2, startPos + len, N, memo));
            }
            if(res == N - startPos){
                break;
            }
        }
        
        memo[startPos] = res;
        return memo[startPos];
    }
    
public:
    int deleteString(string s) {
        const int N = s.length();
        const long long BASE = 131;
        const long long MODULO1 = 1e9 + 7;
        const long long MODULO2 = 1e9 + 9;
        
        RollingHash hash1(s, BASE, MODULO1);
        RollingHash hash2(s, BASE, MODULO2);
        vector<int> memo(N, INF);
        
        return maxOperations(hash1, hash2, 0, N, memo);
    }
};