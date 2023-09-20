#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 3;

    int M;
    cin >> M;

    vector<string> s(N);
    for(int i = 0; i < N; ++i){
        cin >> s[i];
    }

    const int INF = 1e9;
    int res = INF;

    for(int i = 0; i < N * M; ++i){
        for(int j = 0; j < N * M; ++j){
            for(int k = 0; k < N * M; ++k){
                if(i != j && i != k && j != k){
                    if(s[0][i % M] == s[1][j % M] && s[1][j % M] == s[2][k % M]){
                        res = min(res, max({i, j, k}));
                    }
                }
            }
        }
    }

    if(res == INF){
        res = -1;
    }

    cout << res;

    return 0;
}