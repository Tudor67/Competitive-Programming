#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int K;
    cin >> K;

    const int N = S.length();

    // dp[l][r]: min length we can achieve for string S[l .. r]
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for(int len = 1; len <= N; ++len){
        for(int l = 0; l + len - 1 < N; ++l){
            int r = l + len - 1;

            dp[l][r] = r - l + 1;

            if(S[l] == 'o'){
                for(int i = l + 1; i <= r; ++i){
                    if(S[i] == 'f' && dp[l + 1][i - 1] == 0){
                        dp[l][r] = min(dp[l][r], max(dp[i + 1][r] - K, 0));
                    }
                }
            }
            
            for(int i = l; i + 1 <= r; ++i){
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
            }
        }
    }

    cout << dp[0][N - 1];

    return 0;
}