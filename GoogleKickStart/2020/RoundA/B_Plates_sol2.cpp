#include <bits/stdc++.h>
using namespace std;

void solve(const int& TEST_CASE, istream& cin, ostream& cout){
    int N, K, P;
    cin >> N >> K >> P;

    vector<vector<int>> a(N + 1, vector<int>(K + 1));
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= K; ++j){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> prefSum(N + 1, vector<int>(K + 1));
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= K; ++j){
            prefSum[i][j] = prefSum[i][j - 1] + a[i][j];
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(P + 1));
    // dp[i][p]: max beauty achieved by taking p plates from stacks[1 .. i] 

    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= K; ++j){
            for(int p = 0; p <= P - j; ++p){
                dp[i][j + p] = max(dp[i - 1][p] + prefSum[i][j], dp[i][j + p]);
            }
        }
    }

    cout << "Case #" << TEST_CASE << ": " << dp[N][P] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; ++testCase){
        solve(testCase, cin, cout);
    }

    return 0;
}