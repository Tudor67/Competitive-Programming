#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> D(N);
    for(int i = 0; i < N; ++i){
        cin >> D[i];
    }

    vector<int> L(3);
    vector<int> C(3);
    vector<int> K(3);
    for(int i = 1; i <= 2; ++i){
        cin >> L[i] >> C[i] >> K[i];
    }

    if(K[1] > K[2]){
        swap(L[1], L[2]);
        swap(C[1], C[2]);
        swap(K[1], K[2]);
    }

    // At ith iteration:
    //   dp[x]: min number of sensors of type 2 we need to monitor first i sections
    //          when we use x sensors of type 1
    const int INF_INT = 1e9;
    vector<int> dp(K[1] + 1);
    for(int x = 0; x <= K[1]; ++x){
        int y = max(0, (D[0] - x * L[1] + L[2] - 1) / L[2]);
        dp[x] = y;
    }

    for(int i = 1; i < N; ++i){
        vector<int> nextDP(K[1] + 1, INF_INT);
        for(int x = 0; x <= K[1]; ++x){
            for(int nextX = x; nextX <= K[1]; ++nextX){
                int y = max(0, (D[i] - (nextX - x) * L[1] + L[2] - 1) / L[2]);
                nextDP[nextX] = min(nextDP[nextX], dp[x] + y);
            }
        }
        dp = nextDP;
    }

    const long long INF_LONG_LONG = 1e18;
    long long res = INF_LONG_LONG;
    for(long long x = 0; x <= K[1]; ++x){
        long long y = dp[x];
        if(y <= K[2]){
            long long totalCost = x * C[1] + y * C[2];
            res = min(res, totalCost);
        }
    }

    if(res == INF_LONG_LONG){
        res = -1;
    }

    cout << res;

    return 0;
}