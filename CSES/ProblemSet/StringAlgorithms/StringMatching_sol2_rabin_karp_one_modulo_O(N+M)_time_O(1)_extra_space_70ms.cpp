#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void mod(long long& a, const long long& MODULO){
        if(a < 0){
            a += MODULO;
        }else if(a >= MODULO){
            a %= MODULO;
        }
    }

public:
    int countStringMatches(const string& S, const string& P){
        static const long long BASE = 131;
        static const long long MODULO = 1e9 + 7;

        const int N = S.length();
        const int M = P.length();
        
        long long maxBasePow = 1;
        for(int i = 1; i <= M; ++i){
            maxBasePow *= BASE;
            mod(maxBasePow, MODULO);
        }

        long long pHash = 0;
        for(char c: P){
            pHash *= BASE;
            pHash += (c - 'a' + 1);
            mod(pHash, MODULO);
        }

        long long sHash = 0;
        int matchesCount = 0;
        for(int i = 0; i < N; ++i){
            sHash *= BASE;
            sHash += (S[i] - 'a' + 1);
            mod(sHash, MODULO);
            if(i >= M){
                long long redundantTerm = maxBasePow * (S[i - M] - 'a' + 1);
                mod(redundantTerm, MODULO);
                sHash -= redundantTerm;
                mod(sHash, MODULO);
            }
            if(i >= M - 1){
                if(sHash == pHash){
                    matchesCount += 1;
                }
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