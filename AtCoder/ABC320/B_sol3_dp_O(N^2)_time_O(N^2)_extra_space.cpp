#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int N = s.length();

    vector<vector<bool>> isPalindrome(N, vector<bool>(N, false));
    for(int len = 1; len <= N; ++len){
        for(int i = 0; i + len - 1 < N; ++i){
            int j = i + len - 1;
            if(s[i] == s[j]){
                if(i + 1 >= j - 1 || isPalindrome[i + 1][j - 1]){
                    isPalindrome[i][j] = true;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < N; ++i){
        for(int j = i; j < N; ++j){
            if(isPalindrome[i][j]){
                res = max(res, j - i + 1);
            }
        }
    }

    cout << res;

    return 0;
}