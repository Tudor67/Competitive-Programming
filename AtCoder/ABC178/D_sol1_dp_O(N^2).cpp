#include <bits/stdc++.h>
using namespace std;

int main(){
    const long long MODULO = (1e9) + 7;
    long long n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    if(n >= 3){
        dp[3] = 1;
        for(int i = 4; i <= n; ++i){
            dp[i] = 1;
            for(int j = 3; j + 3 <= i; ++j){
                dp[i] = (dp[i] + dp[j]) % MODULO;
            }
        }
    }

    cout << dp[n];
    return 0;
}