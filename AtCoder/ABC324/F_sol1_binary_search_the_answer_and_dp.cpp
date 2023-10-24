#include <bits/stdc++.h>
using namespace std;

const double INF = 1e18;

using Edge = tuple<int, int, int>;
using Graph = vector<vector<Edge>>;

bool isValid(const Graph& G, const double X){
    const int N = G.size();

    vector<double> dp(N, -INF);
    dp[0] = 0;

    for(int node = 0; node < N; ++node){
        if(dp[node] != -INF){
            for(const Edge& EDGE: G[node]){
                int nextNode = get<0>(EDGE);
                int edgeBeauty = get<1>(EDGE);
                int edgeCost = get<2>(EDGE);

                double w = edgeBeauty - edgeCost * X;

                dp[nextNode] = max(dp[nextNode], dp[node] + w);
            }
        }
    }

    return (dp[N - 1] >= 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    Graph G(N);
    for(int i = 0; i < M; ++i){
        int x, y, b, c;
        cin >> x >> y >> b >> c;
        G[x - 1].push_back({y - 1, b, c});
    }

    double l = 0;
    double r = 2e5 + 5;
    while(r - l > 1e-9){
        double mid = (l + r) / 2;
        if(isValid(G, mid)){
            l = mid;
        }else{
            r = mid;
        }
    }

    cout << fixed << setprecision(10) << (l + r) / 2;

    return 0;
}