#include <bits/stdc++.h>
using namespace std;

using T3 = tuple<int, long long, long long>; // (nextNode, dx, dy)
using Graph = vector<vector<T3>>;
using Coordinate = pair<long long, long long>;

void dfs(int node, vector<bool>& vis, const Graph& G, vector<Coordinate>& coordOf){
    if(vis[node]){
        return;
    }

    vis[node] = true;
    for(const T3& T: G[node]){
        int nextNode = get<0>(T);
        long long dx = get<1>(T);
        long long dy = get<2>(T);

        if(!vis[nextNode]){
            coordOf[nextNode].first = coordOf[node].first + dx;
            coordOf[nextNode].second = coordOf[node].second + dy;
            dfs(nextNode, vis, G, coordOf);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    Graph G(N);
    for(int i = 0; i < M; ++i){
        int A, B, dx, dy;
        cin >> A >> B >> dx >> dy;
        A -= 1;
        B -= 1;
        G[A].push_back({B,  dx,  dy});
        G[B].push_back({A, -dx, -dy});
    }

    vector<Coordinate> coordOf(N);
    vector<bool> vis(N, false);
    coordOf[0] = {0, 0};
    dfs(0, vis, G, coordOf);

    for(int node = 0; node < N; ++node){
        if(vis[node]){
            cout << coordOf[node].first << " " << coordOf[node].second;
        }else{
            cout << "undecidable";
        }
        cout << "\n";
    }

    return 0;
}