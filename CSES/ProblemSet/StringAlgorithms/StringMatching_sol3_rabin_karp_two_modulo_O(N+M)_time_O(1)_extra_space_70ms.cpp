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
        static const long long MODULO1 = 1e9 + 7;
        static const long long MODULO2 = 1e9 + 9;

        const int N = S.length();
        const int M = P.length();
        
        long long maxBasePow1 = 1;
        long long maxBasePow2 = 1;
        for(int i = 1; i <= M; ++i){
            maxBasePow1 *= BASE;
            maxBasePow2 *= BASE;
            mod(maxBasePow1, MODULO1);
            mod(maxBasePow2, MODULO2);
        }

        long long pHash1 = 0;
        long long pHash2 = 0;
        for(char c: P){
            pHash1 *= BASE;
            pHash2 *= BASE;
            pHash1 += (c - 'a' + 1);
            pHash2 += (c - 'a' + 1);
            mod(pHash1, MODULO1);
            mod(pHash2, MODULO2);
        }

        long long sHash1 = 0;
        long long sHash2 = 0;
        int matchesCount = 0;
        for(int i = 0; i < N; ++i){
            sHash1 *= BASE;
            sHash2 *= BASE;
            sHash1 += (S[i] - 'a' + 1);
            sHash2 += (S[i] - 'a' + 1);
            mod(sHash1, MODULO1);
            mod(sHash2, MODULO2);
            if(i >= M){
                long long redundantTerm1 = maxBasePow1 * (S[i - M] - 'a' + 1);
                long long redundantTerm2 = maxBasePow2 * (S[i - M] - 'a' + 1);
                mod(redundantTerm1, MODULO1);
                mod(redundantTerm2, MODULO2);
                sHash1 -= redundantTerm1;
                sHash2 -= redundantTerm2;
                mod(sHash1, MODULO1);
                mod(sHash2, MODULO2);
            }
            if(i >= M - 1){
                if(sHash1 == pHash1 && sHash2 == pHash2){
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