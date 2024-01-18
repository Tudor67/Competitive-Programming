#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }

    vector<int> L(N + 2);
    for(int i = 1; i <= N; ++i){
        L[i] = min(L[i - 1] + 1, A[i]);
    }

    vector<int> R(N + 2);
    for(int i = N; i >= 1; --i){
        R[i] = min(A[i], 1 + R[i + 1]);
    }

    int res = 0;
    for(int i = 1; i <= N; ++i){
        int k = min(L[i], R[i]);
        res = max(res, k);
    }

    cout << res;

    return 0;
}