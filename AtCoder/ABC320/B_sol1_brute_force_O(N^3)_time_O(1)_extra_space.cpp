#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s, int i, int j){
    while(i < j){
        if(s[i] == s[j]){
            i += 1;
            j -= 1;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int N = s.length();

    int res = 0;
    for(int i = 0; i < N; ++i){
        for(int j = i; j < N; ++j){
            if(isPalindrome(s, i, j)){
                res = max(res, j - i + 1);
            }
        }
    }

    cout << res;

    return 0;
}