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
    struct PairHash{
        size_t operator()(const pair<int, int>& P) const{
            size_t a = P.first;
            size_t b = P.second;
            return (a << 30) | b;
        }
    };
    
    int findDuplicatePos(const string& S, const RollingHash& HASH_OBJ1, const RollingHash& HASH_OBJ2, const int& K){
        if(K == 0){
            return 0;
        }
        const int N = S.length();
        unordered_set<pair<int, int>, PairHash> visHashValues;
        for(int i = 0; i + K - 1 < N; ++i){
            int rangeHash1 = HASH_OBJ1.getRangeHash(i, i + K - 1);
            int rangeHash2 = HASH_OBJ2.getRangeHash(i, i + K - 1);
            if(visHashValues.count({rangeHash1, rangeHash2})){
                return i;
            }
            visHashValues.insert({rangeHash1, rangeHash2});
        }
        return -1;
    }
    
public:
    string longestDupSubstring(string s) {
        const int N = s.length();
        const RollingHash HASH_OBJ1(s, 131, 1e9 + 7);
        const RollingHash HASH_OBJ2(s, 131, 1e9 + 9);
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(findDuplicatePos(s, HASH_OBJ1, HASH_OBJ2, mid) >= 0){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return s.substr(findDuplicatePos(s, HASH_OBJ1, HASH_OBJ2, r), r);
    }
};