#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, M, L, R;
    cin >> A >> M >> L >> R;

    long long shift = -A;
    A += shift;
    L += shift;
    R += shift;

    if(R < 0){
        L = -L;
        R = -R;
        swap(L, R);
    }

    long long res = R / M + 1;
    if(L < 0){
        res += -L / M;
    }else if(L > 0){
        res -= (L - 1) / M + 1;
    }

    cout << res;

    return 0;
}