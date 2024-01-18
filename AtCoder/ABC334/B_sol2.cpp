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

    long long x = L / M;
    long long y = R / M;
    if(x * M < L){
        x += 1;
    }
    if(y * M > R){
        y -= 1;
    }

    cout << y - x + 1;

    return 0;
}