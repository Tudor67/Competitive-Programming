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

    for(char targetChar = '0'; targetChar <= '9'; ++targetChar){
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);

        do{
            int i = 0;
            int t = 0;
            while(i < N && t < N * M){
                if(s[p[i]][t % M] == targetChar){
                    i += 1;
                }
                t += 1;
            }
            
            if(i == N){
                res = min(res, t - 1);
            }
        }while(next_permutation(p.begin(), p.end()));
    }

    if(res == INF){
        res = -1;
    }

    cout << res;

    return 0;
}