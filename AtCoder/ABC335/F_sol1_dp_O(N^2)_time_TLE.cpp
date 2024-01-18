#include <bits/stdc++.h>
using namespace std;

const int MODULO = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    // dp[i]: the number of possible sets of squares that can be painted black
    //        when we start from ith square
    vector<int> dp(N);
    for(int i = N - 1; i >= 0; --i){
        dp[i] = 1;
        for(int j = i + A[i]; j < N; j += A[i]){
            dp[i] += dp[j];
            dp[i] %= MODULO;
        }
    }

    cout << dp[0];

    return 0;
}