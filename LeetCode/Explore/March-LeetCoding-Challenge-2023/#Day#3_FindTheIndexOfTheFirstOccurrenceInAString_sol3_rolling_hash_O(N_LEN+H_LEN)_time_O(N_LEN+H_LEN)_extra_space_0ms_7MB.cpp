class RollingHash{
private:
    const long long BASE;
    const long long MODULO;
    vector<long long> p;
    vector<long long> h;

public:
    RollingHash(const string& S, const long long& BASE, const long long& MODULO): BASE(BASE), MODULO(MODULO){
        const int N = S.length();
        p.resize(N);
        h.resize(N);
        p[0] = 1;
        h[0] = S[0];
        for(int i = 1; i < N; ++i){
            p[i] = (p[i - 1] * BASE) % MODULO;
            h[i] = (h[i - 1] * BASE + S[i]) % MODULO;
        }
    }

    long long getRangeHash(const int& L, const int& R){
        if(L > R){
            return -1;
        }
        if(L == 0){
            return h[R];
        }
        return (h[R] - (h[L - 1] * p[R - (L - 1)]) % MODULO + MODULO) % MODULO;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int N_LEN = needle.length();
        const int H_LEN = haystack.length();

        const long long BASE = 131;
        const long long MODULO = 1e9 + 7;

        long long needleHash = RollingHash(needle, BASE, MODULO).getRangeHash(0, N_LEN - 1);

        RollingHash haystackHashObj(haystack, BASE, MODULO);
        for(int i = 0; i + N_LEN - 1 < H_LEN; ++i){
            if(needleHash == haystackHashObj.getRangeHash(i, i + N_LEN - 1)){
                if(equal(needle.begin(), needle.end(), haystack.begin() + i)){
                    return i;
                }
            }
        }

        return -1;
    }
};