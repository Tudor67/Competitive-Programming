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

    void markMatches(const string& S, const string& P,
                     const long long& BASE, const long long& MODULO,
                     vector<int>& matches){
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
                    matches[i - M + 1] += 1;
                }
            }
        }
    }

public:
    int countStringMatches(const string& S, const string& P){
        const int N = S.length();
        vector<int> matches(N, 0);

        const long long BASE = 131;
        const vector<long long> MODULOS = {(int)(1e9 + 7),
                                           (int)(1e9 + 9),
                                           (int)(1e9 + 21)};

        for(const long long& MODULO: MODULOS){
            markMatches(S, P, BASE, MODULO, matches);
        }

        int matchesCount = count(matches.begin(), matches.end(), (int)MODULOS.size());
        return matchesCount;
    }
};

int main(){
    string s, p;
    cin >> s >> p;

    cout << Solution().countStringMatches(s, p);

    return 0;
}