#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> C(2 * N);
    vector<int> fTotal(N);
    for(int i = 0; i < N; ++i){
        cin >> C[i];
        C[i] -= 1;
        C[i + N] = C[i];
        fTotal[C[i]] += 1;
    }

    int boxes = 0;
    int balls = 0;
    vector<int> f(N);
    for(int l = 0, r = 0; l < N; ++l){
        while(r - l + 1 <= N && boxes < M){
            if(f[C[r]] % K == 0){
                boxes += 1;
                balls += min(K, fTotal[C[r]] - f[C[r]]);
            }
            f[C[r]] += 1;
            r += 1;
        }

        cout << balls << "\n";
        
        f[C[l]] -= 1;
        if(f[C[l]] % K == 0){
            boxes -= 1;
            balls -= min(K, fTotal[C[l]] - f[C[l]]);
        }
    }

    return 0;
}