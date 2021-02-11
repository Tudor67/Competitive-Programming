#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> A(M);
    vector<int> B(M);
    for(int i = 0; i < M; ++i){
        cin >> A[i] >> B[i];
        A[i] -= 1;
        B[i] -= 1;
    }

    int K;
    cin >> K;

    vector<int> C(K);
    vector<int> D(K);
    for(int i = 0; i < K; ++i){
        cin >> C[i] >> D[i];
        C[i] -= 1;
        D[i] -= 1;
    }

    const int FULL_MASK = (1 << K) - 1;
    vector<bool> vis(N);
    int answer = 0;
    for(int mask = 0; mask <= FULL_MASK; ++mask){
        fill(vis.begin(), vis.end(), false);
        for(int bit = 0; bit < K; ++bit){
            if((mask >> bit) & 1){
                vis[C[bit]] = true;
            }else{
                vis[D[bit]] = true;
            }
        }
        int validConditions = 0;
        for(int i = 0; i < M; ++i){
            validConditions += (vis[A[i]] && vis[B[i]]);
        }
        answer = max(validConditions, answer);
    }

    cout << answer;

    return 0;
}