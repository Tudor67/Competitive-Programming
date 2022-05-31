class Hash{
private:
    const long long MODULO;
    const long long BASE = 131;
    vector<long long> h;
    vector<long long> p;
    
public:
    Hash(const string& S, const long long& MODULO): MODULO(MODULO){
        const int N = S.length();
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
    int countSubstrings(string s) {
        const int N = s.length();
        const int MODULO = 1e9 + 7;
        
        Hash hashObj(s, MODULO);
        Hash hashObjRev(string(s.rbegin(), s.rend()), MODULO);
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            for(int delta: {0, 1}){
                int end1 = i;
                int start2 = i + delta;
                int l = 0;
                int r = min(end1 + 1, N - start2);
                while(l != r){
                    int mid = (l + r + 1) / 2;
                    if(hashObj.getRangeHash(end1 - mid + 1, end1) ==
                       hashObjRev.getRangeHash(N - 1 - (start2 + mid - 1), N - 1 - start2)){
                        l = mid;
                    }else{
                        r = mid - 1;
                    }
                }
                res += r;
            }
        }
        
        return res;
    }
};