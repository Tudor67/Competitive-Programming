#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, X;
    cin >> N >> X;

    vector<int> a(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    
    const int TOTAL_SUM = accumulate(a.begin() + 1, a.end(), 0);
    vector<vector<int>> dp(N + 1, vector<int>(N, -1));
    vector<vector<vector<int>>> elems(N + 1, vector<vector<int>>(N + 1));
    // dp[k][rem]: max sum S_k of k elements with rem = S_k % k

    dp[N][TOTAL_SUM % N] = TOTAL_SUM;
    for(int i = 1; i <= N; ++i){
        elems[N][TOTAL_SUM % N].push_back(a[i]);
    }

    for(int k = N; k >= 2; --k){
        for(int rem = 0; rem < k; ++rem){
            if(dp[k][rem] != -1){
                int sum = dp[k][rem];
                for(int i = 0; i < k; ++i){
                    int nextSum = sum - elems[k][rem][i];
                    int nextRem = nextSum % (k - 1);
                    if(dp[k - 1][nextRem] < nextSum){
                        dp[k - 1][nextRem] = nextSum;
                        elems[k - 1][nextRem] = elems[k][rem];
                        elems[k - 1][nextRem][i] = elems[k - 1][nextRem].back();
                        elems[k - 1][nextRem].pop_back();
                    }
                }
            }
        }
    }

    long long answer = X;
    for(int k = 1; k <= N; ++k){
        int rem = X % k;
        if(dp[k][rem] != -1){
            answer = min((X - dp[k][rem]) / k, answer);
        }
    }

    cout << answer;

    return 0;
}