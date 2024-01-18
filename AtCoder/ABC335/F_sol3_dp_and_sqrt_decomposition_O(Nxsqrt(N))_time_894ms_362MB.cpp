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

    const int SQRT_N = floor(sqrt(N)) + 1;
    // dp[i]: the number of possible sets of squares that can be painted black
    //        when we start from ith square
    vector<int> dp(N);
    vector<vector<int>> delta(N, vector<int>(SQRT_N));
    for(int i = N - 1; i >= 0; --i){
        dp[i] = 1;

        if(A[i] < SQRT_N){
            dp[i] += delta[i][A[i]];
            dp[i] %= MODULO;
        }else{
            for(int j = i + A[i]; j < N; j += A[i]){
                dp[i] += dp[j];
                dp[i] %= MODULO;
            }
        }

        for(int j = 1; j < SQRT_N && i - j >= 0; ++j){
            delta[i - j][j] += delta[i][j];
            delta[i - j][j] %= MODULO;
            delta[i - j][j] += dp[i];
            delta[i - j][j] %= MODULO;
        }
    }

    cout << dp[0];

    return 0;
}