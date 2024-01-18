#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    int res = 0;
    while(x % 2 == 0){
        res += 1;
        x /= 2;
    }

    cout << res;

    return 0;
}