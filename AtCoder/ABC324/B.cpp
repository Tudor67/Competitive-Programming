#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;

    while(x % 2 == 0){
        x /= 2;
    }

    while(x % 3 == 0){
        x /= 3;
    }

    if(x == 1){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}