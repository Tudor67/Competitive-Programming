#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, Q;
    cin >> N >> Q;

    vector<long long> R(N);
    for(int i = 0; i < N; ++i){
        cin >> R[i];
    }

    vector<long long> X(Q);
    for(int i = 0; i < Q; ++i){
        cin >> X[i];
    }

    sort(R.begin(), R.end());

    vector<long long> prefSum(N);
    prefSum[0] = R[0];
    for(int i = 1; i < N; ++i){
        prefSum[i] = prefSum[i - 1] + R[i];
    }

    vector<int> res(Q);
    for(int i = 0; i < Q; ++i){
        res[i] = upper_bound(prefSum.begin(), prefSum.end(), X[i]) - prefSum.begin();
    }

    for(int elem: res){
        cout << elem << "\n";
    }

    return 0;
}