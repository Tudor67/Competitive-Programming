#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll S;
    cin >> S;
    S *= 2;

    ll answer = 0;
    for(ll n = 1; n * n <= S; ++n){
        if(S % n == 0){
            for(const pair<ll, ll>& P: set<pair<ll, ll>>{{n, S / n}, {S / n, n}}){
                ll div1 = P.first;;
                ll div2 = P.second;
                ll rem2 = div2 - (div1 - 1);
                if(rem2 % 2 == 0){
                    answer += 1;
                }
            }
        }
    }

    cout << answer;

    return 0;
}