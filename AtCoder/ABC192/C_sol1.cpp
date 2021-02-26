#include <bits/stdc++.h>
using namespace std;

int strToInt(const string& S){
    int num = 0;
    for(int i = 0; i < (int)S.length(); ++i){
        num = 10 * num + (S[i] - '0');
    }
    return num;
}

int f(int x){
    string s = to_string(x);
    sort(s.begin(), s.end());
    string sRev(s.rbegin(), s.rend());
    return strToInt(sRev) - strToInt(s);
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