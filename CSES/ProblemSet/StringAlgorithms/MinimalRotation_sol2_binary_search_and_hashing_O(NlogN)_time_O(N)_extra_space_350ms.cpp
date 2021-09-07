#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    const long long BASE = 131;
    const long long MODULO = 1e9 + 7;

    void mod(long long& a, const long long& MODULO){
        if(a >= MODULO){
            a %= MODULO;
        }
    }

    long long modInverse(long long a, const long long& MODULO){
        mod(a, MODULO);
        long long n = MODULO - 2;
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res *= a;
                mod(res, MODULO);
            }
            a *= a;
            mod(a, MODULO);
            n /= 2;
        }
        return res;
    }

    long long getRangeHash(int l, int r, vector<long long>& prefHash, long long invPow){
        long long rangeHash = prefHash[r];
        if(l > 0){
            rangeHash -= prefHash[l - 1];
            if(rangeHash < 0){
                rangeHash += MODULO;
            }
            mod(rangeHash, MODULO);
        }
        rangeHash *= invPow;
        mod(rangeHash, MODULO);
        return rangeHash;
    }

public:
    int minimalRotationIdx(const string& S){
        const int N = S.length();
        const string SS = S + S;

        vector<long long> prefHash(2 * N, 0);
        prefHash[0] = SS[0] - 'a';
        long long p = BASE;
        for(int i = 1; i < 2 * N; ++i){
            prefHash[i] = prefHash[i - 1] + p * (SS[i] - 'a');
            mod(prefHash[i], MODULO);
            p *= BASE;
            mod(p, MODULO);
        }

        vector<long long> invPow(N);
        invPow[0] = 1;
        long long invBase = modInverse(BASE, MODULO);
        for(int i = 1; i < N; ++i){
            invPow[i] = invPow[i - 1] * invBase;
            mod(invPow[i], MODULO);
        }

        int k = 0;
        for(int i = 1; i < N; ++i){
            if(S[k] < S[i]){
                continue;
            }
            int l = 1;
            int r = N;
            while(l != r){
                int mid = (l + r) / 2;
                long long kHash = getRangeHash(k, k + mid - 1, prefHash, invPow[k]);
                long long iHash = getRangeHash(i, i + mid - 1, prefHash, invPow[i]);
                if(kHash == iHash){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            if(SS[k + r - 1] > SS[i + r - 1]){
                k = i;
            }
        }

        return k;
    }
};

int main(){
    string s;
    cin >> s;

    int minIdx = Solution().minimalRotationIdx(s);
    string minS = s.substr(minIdx) + s.substr(0, minIdx);

    cout << minS;

    return 0;
}