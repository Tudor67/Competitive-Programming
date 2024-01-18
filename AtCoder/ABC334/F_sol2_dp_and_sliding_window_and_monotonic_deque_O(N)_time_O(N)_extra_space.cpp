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

    vector<Point> p(N + 2);
    for(int i = 1; i <= N; ++i){
        cin >> p[i].first >> p[i].second;
    }

    vector<long double> prefSum(N + 2);
    for(int i = 2; i <= N; ++i){
        prefSum[i] = prefSum[i - 1] + dist(p[i - 1], p[i]);
    }

    const long double INF = 1e18;
    vector<long double> dp(N + 1, INF);
    deque<pair<long double, int>> dq;

    dp[0] = 0;
    dq.push_back({dp[0] + dist(santa, p[1]) - prefSum[1], 0});

    for(int i = 1; i <= N; ++i){
        while(!dq.empty() && i - dq.front().second > K){
            dq.pop_front();
        }
        
        dp[i] = dq.front().first + prefSum[i] + dist(p[i], santa);

        int j = i;
        while(!dq.empty() && dq.back().first >= dp[j] + dist(santa, p[j + 1]) - prefSum[j + 1]){
            dq.pop_back();
        }
        dq.push_back({dp[j] + dist(santa, p[j + 1]) - prefSum[j + 1], j});
    }

    cout << fixed << setprecision(10);
    cout << dp[N];

    return 0;
}