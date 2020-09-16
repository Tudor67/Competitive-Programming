#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max({a * c, a * d, b * c, b * d});
    return 0;
}