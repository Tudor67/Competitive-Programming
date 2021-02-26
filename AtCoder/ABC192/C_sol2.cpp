#include <bits/stdc++.h>
using namespace std;

int f(int x){
    string s = to_string(x);
    sort(s.begin(), s.end());
    string sRev(s.rbegin(), s.rend());
    return stoi(sRev) - stoi(s);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> a(K + 1);
    a[0] = N;

    for(int i = 1; i <= K; ++i){
        a[i] = f(a[i - 1]);
    }

    cout << a[K];

    return 0;
}