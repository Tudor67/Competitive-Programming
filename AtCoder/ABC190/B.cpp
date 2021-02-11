#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, S, D;
    cin >> N >> S >> D;

    long long X, Y;
    bool ok = false;
    for(int i = 1; i <= N; ++i){
        cin >> X >> Y;
        if(X < S && Y > D){
            ok = true;
        }
    }

    if(ok){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}