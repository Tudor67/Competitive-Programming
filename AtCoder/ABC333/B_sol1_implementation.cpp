#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    string T;

    cin >> S;
    cin >> T;

    int ds = abs(S[0] - S[1]);
    int dt = abs(T[0] - T[1]);
    ds = min(ds, 5 - ds);
    dt = min(dt, 5 - dt);

    if(ds == dt){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}