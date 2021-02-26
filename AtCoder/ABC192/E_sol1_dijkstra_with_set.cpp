#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P2 = pair<ll, int>;
using T3 = tuple<int, ll, ll>;

const ll INF = 2e18 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;

    X -= 1;
    Y -= 1;

    vector<vector<T3>> g(N);
    for(int i = 0; i < M; ++i){
        int A, B, T, K;
        cin >> A >> B >> T >> K;
        A -= 1;
        B -= 1;
        g[A].push_back({B, T, K});
        g[B].push_back({A, T, K});
    }

    set<P2> minSet;
    vector<ll> dist(N, INF);
    minSet.insert({0, X});
    dist[X] = 0;

    while(!minSet.empty()){
        ll d = minSet.begin()->first;
        int node = minSet.begin()->second;
        minSet.erase(minSet.begin());

        for(const T3& TT: g[node]){
            int nextNode; ll T, K;
            tie(nextNode, T, K) = TT;

            ll nextD = K * ((d + K - 1) / K) + T;
            if(nextD < dist[nextNode]){
                auto it = minSet.find({dist[nextNode], nextNode});
                if(it != minSet.end()){
                    minSet.erase(it);
                }
                dist[nextNode] = nextD;
                minSet.insert({nextD, nextNode});
            }
        }
    }

    ll answer = -1;
    if(dist[Y] != INF){
        answer = dist[Y];
    }

    cout << answer;
    
    return 0;
}