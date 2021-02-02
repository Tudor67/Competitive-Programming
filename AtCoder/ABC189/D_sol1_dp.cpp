#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<string> s(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> s[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));
    // dp[i][true]:  number of tuples (x[0], x[1], ..., x[i]) with y[i] = true
    // dp[i][false]: number of tuples (x[0], x[1], ..., x[i]) with y[i] = false
    
    dp[0][true] = 1;
    dp[0][false] = 1;

    for(int i = 1; i <= N; ++i){
        if(s[i] == "OR"){
            dp[i][true] = 2 * dp[i - 1][true] + dp[i - 1][false];
            dp[i][false] = dp[i - 1][false];
        }else{
            dp[i][true] = dp[i - 1][true];
            dp[i][false] = 2 * dp[i - 1][false] + dp[i - 1][true];
        }
    }

    cout << dp[N][true];

    return 0;
}