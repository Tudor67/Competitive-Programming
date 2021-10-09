#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countStringMatches(const string& S, const string& P){
        const int N = S.length();
        const int M = P.length();
        
        const string PS = P + "$" + S;
        const int L = PS.length();

        vector<int> p(L);
        int matchesCount = 0;
        for(int i = 1; i < L; ++i){
            int k = p[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = p[k - 1];
            }
            if(PS[k] == PS[i]){
                p[i] = k + 1;
            }
            if(p[i] == M){
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