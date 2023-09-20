#include <bits/stdc++.h>
using namespace std;

int fastPow(int a, int n){
    int res = 1;
    while(n > 0){
        if(n & 1){
            res *= a;
        }
        n >>= 1;
        if(n > 0){
            a *= a;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    cout << fastPow(A, B) + fastPow(B, A);

    return 0;
}