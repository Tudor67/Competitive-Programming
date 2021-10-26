#include <bits/stdc++.h>
using namespace std;

class RollingHash{
private:
    const long long MODULO;
    vector<long long> h;
    vector<long long> p;

    void mod(long long& a){
        if(a < 0){
            a += MODULO;
        }else if(a >= MODULO){
            a %= MODULO;
        }
    }

public:
    RollingHash(const string& S, const long long& BASE, const long long& MODULO): MODULO(MODULO){
        const char MIN_ELEM = *min_element(S.begin(), S.end());
        const int N = S.length();
        h.resize(N);
        p.resize(N);
        h[0] = S[0] - MIN_ELEM + 1;
        p[0] = 1;
        for(int i = 1; i < N; ++i){
            h[i] = h[i - 1] * BASE + (S[i] - MIN_ELEM + 1);
            mod(h[i]);
            p[i] = p[i - 1] * BASE;
            mod(p[i]);
        }
    }

    long long getRangeHash(const int& L, const int& R){
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

class Solution{
public:
    int countStringMatches(const string& S, const string& P){
        const int N = S.length();
        const int M = P.length();

        const string PS = P + "$" + S;
        const int L = PS.length();

        RollingHash h1(PS, 131, (long long)(1e9 + 7));
        RollingHash h2(PS, 131, (long long)(1e9 + 9));

        int matchesCount = 0;
        long long h1P = h1.getRangeHash(0, M - 1);
        long long h2P = h2.getRangeHash(0, M - 1);
        for(int i = 2 * M; i < L; ++i){
            if(h1P == h1.getRangeHash(i - M + 1, i) &&
               h2P == h2.getRangeHash(i - M + 1, i)){
                matchesCount += 1;
            }
        }

        return matchesCount;
    }
};

int main(){
    string s, p;
    cin >> s >> p;

    cout << Solution().countStringMatches(s, p);

    return 0;
}