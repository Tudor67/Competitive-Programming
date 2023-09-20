#include <bits/stdc++.h>
using namespace std;

int myPow(int a, int n){
    int p = 1;
    for(int i = 1; i <= n; ++i){
        p *= a;
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    cout << myPow(A, B) + myPow(B, A);

    return 0;
}