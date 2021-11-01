class RollingHash{
private:
    const long long MODULO;
    vector<long long> h;
    vector<long long> p;
    
    void mod(long long& a) const{
        if(a < 0){
            a += MODULO;
        }else if(a >= MODULO){
            a %= MODULO;
        }
    }
    
public:
    RollingHash(const string& S, const long long& BASE, const long long& MODULO): MODULO(MODULO){
        const int N = S.length();
        h.resize(N);
        p.resize(N);
        h[0] = S[0] - 'a' + 1;
        p[0] = 1;
        for(int i = 1; i < N; ++i){
            h[i] = h[i - 1] * BASE + (S[i] - 'a' + 1);
            mod(h[i]);
            p[i] = p[i - 1] * BASE;
            mod(p[i]);
        }
    }
    
    int getRangeHash(const int& L, const int& R) const{
        long long rangeHash = h[R];
        if(L > 0){
            long long prefHash = h[L - 1] * p[R - L + 1];
            mod(prefHash);
            rangeHash -= prefHash;
            mod(rangeHash);
        }
        return rangeHash;
    }
};

class Solution {
private:
    int findDuplicatePos(const string& S, const RollingHash& HASH_OBJ, const int& K){
        if(K == 0){
            return 0;
        }
        const int N = S.length();
        unordered_map<int, vector<int>> startIndicesOf;
        for(int i = 0; i + K - 1 < N; ++i){
            int rangeHash = HASH_OBJ.getRangeHash(i, i + K - 1);
            if(startIndicesOf.count(rangeHash)){
                for(int startIdx: startIndicesOf[rangeHash]){
                    if(S.compare(startIdx, K, S, i, K) == 0){
                        return i;
                    }
                }
            }
            startIndicesOf[rangeHash].push_back(i);
        }
        return -1;
    }
    
public:
    string longestDupSubstring(string s) {
        const int N = s.length();
        const RollingHash HASH_OBJ(s, 131, 1e9 + 7);
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(findDuplicatePos(s, HASH_OBJ, mid) >= 0){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return s.substr(findDuplicatePos(s, HASH_OBJ, r), r);
    }
};