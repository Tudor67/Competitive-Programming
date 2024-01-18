#include <bits/stdc++.h>
using namespace std;

using Point = pair<long long, long long>;

long double dist(const Point& A, const Point& B){
    long double dx = A.first - B.first;
    long double dy = A.second - B.second;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    Point santa;
    cin >> santa.first >> santa.second;

    vector<Point> p(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> p[i].first >> p[i].second;
    }

    const long double INF = 1e18;
    vector<long double> dp(N + 1, INF);

    dp[0] = 0;
    dp[1] = 2 * dist(santa, p[1]);

    for(int i = 2; i <= N; ++i){
        dp[i] = dp[i - 1] + 2 * dist(p[i], santa);
        long double jiDist = 0;
        for(int j = i - 1; j >= max(1, i - K + 1); --j){
            jiDist += dist(p[j], p[j + 1]);
            dp[i] = min(dp[i],
                        dp[j - 1] + dist(santa, p[j]) + jiDist + dist(p[i], santa));
        }
    }

    cout << fixed << setprecision(10);
    cout << dp[N];

    return 0;
}