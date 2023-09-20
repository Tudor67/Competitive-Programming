#include <bits/stdc++.h>
using namespace std;

void updateMin(int& a, int b){
    if(a > b){
        a = b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H;
    cin >> N >> H;

    vector<int> X(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> X[i];
    }

    vector<int> P(N + 1);
    vector<int> F(N + 1);
    for(int i = 1; i <= N - 1; ++i){
        cin >> P[i] >> F[i];
    }

    const int INF = 1e9;
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(H + 1, vector<int>(H + 1, INF)));

    for(int b = 0; b <= H; ++b){
        dp[0][H][b] = 0;
    }

    for(int i = 0; i <= N - 1; ++i){
        for(int a = 0; a <= H; ++a){
            for(int b = 0; b <= H; ++b){
                int dist = X[i + 1] - X[i];
                if(dp[i][a][b] == INF){
                    continue;
                }
                if(a - dist < 0){
                    continue;
                }
                if(b + dist > H){
                    continue;
                }
                updateMin(dp[i + 1][a - dist][b + dist], dp[i][a][b]);
                updateMin(dp[i + 1][min(a - dist + F[i + 1], H)][b + dist], dp[i][a][b] + P[i + 1]);
                updateMin(dp[i + 1][a - dist][max(b - F[i + 1] + dist, 0)], dp[i][a][b] + P[i + 1]);
            }
        }
    }

    int res = INF;
    for(int a = 0; a <= H; ++a){
        for(int b = 0; b <= a; ++b){
            updateMin(res, dp[N][a][b]);
        }
    }

    if(res == INF){
        res = -1;
    }

    cout << res;

    return 0;
}