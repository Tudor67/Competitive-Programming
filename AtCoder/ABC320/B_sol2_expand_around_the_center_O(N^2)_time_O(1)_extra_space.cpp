#include <bits/stdc++.h>
using namespace std;

int maxPalindromeLength(string& s, int i, int j){
    const int N = s.length();
    while(0 <= i && j < N && s[i] == s[j]){
        i -= 1;
        j += 1;
    }
    return j - i - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int N = s.length();

    int res = 0;
    for(int i = 0; i < N; ++i){
        res = max(res, maxPalindromeLength(s, i, i));
        res = max(res, maxPalindromeLength(s, i, i + 1));
    }

    cout << res;

    return 0;
}