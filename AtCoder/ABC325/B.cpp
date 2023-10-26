#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> W(N);
    vector<int> X(N);
    for(int i = 0; i < N; ++i){
        cin >> W[i] >> X[i];
    }

    int res = 0;
    for(int h = 0; h <= 23; ++h){
        int totalWorkers = 0;
        for(int i = 0; i < N; ++i){
            int baseHour = (X[i] + h) % 24;
            if(9 <= baseHour && baseHour + 1 <= 18){
                totalWorkers += W[i];
            }
        }
        res = max(res, totalWorkers);
    }

    cout << res;

    return 0;
}