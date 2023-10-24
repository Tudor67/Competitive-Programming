#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string P;
    cin >> P;

    sort(P.rbegin(), P.rend());

    int res = 0;
    long long maxNum = stoll(P);
    for(long long i = 0; i * i <= maxNum; ++i){
        string S = to_string(i * i);

        S.resize(N, '0');
        sort(S.rbegin(), S.rend());

        if(S == P){
            res += 1;
        }
    }

    cout << res;

    return 0;
}