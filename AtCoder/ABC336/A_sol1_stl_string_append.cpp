#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string s = "L";
    s.append(N, 'o');
    s += "ng";

    cout << s;

    return 0;
}