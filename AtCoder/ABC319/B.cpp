#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string s(N + 1, '-');
    for(int i = 0; i <= N; ++i){
        for(int j = 1; j <= 9; ++j){
            if(N % j == 0 && i % (N / j) == 0){
                s[i] = char('0' + j);
                break;
            }
        }
    }

    cout << s;

    return 0;
}