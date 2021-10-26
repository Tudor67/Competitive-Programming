#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countStringMatches(const string& S, const string& P){
        const int N = S.length();
        const int M = P.length();

        const string PS = P + "$" + S;
        const int L = PS.length();

        vector<int> z(L);
        int l = 0;
        int r = 0;
        int matchesCount = 0;
        for(int i = 1; i < L; ++i){
            if(i <= r){
                z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < L && PS[z[i]] == PS[i + z[i]]){
                z[i] += 1;
            }
            if(i + z[i] - 1 >= r){
                l = i;
                r = i + z[i] - 1;
            }
            if(z[i] == M){
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