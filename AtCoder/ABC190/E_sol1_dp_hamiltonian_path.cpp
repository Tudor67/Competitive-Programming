#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
const int INF = 1e7;

void bfs(const int& SRC_NODE, const Graph& G, vector<int>& dist){
    fill(dist.begin(), dist.end(), INF);
    queue<int> q;
    q.push(SRC_NODE);
    dist[SRC_NODE] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int nextNode: G[node]){
            if(dist[nextNode] == INF){
                q.push(nextNode);
                dist[nextNode] = 1 + dist[node];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    Graph g(N);
    int x, y;
    for(int i = 0; i < M; ++i){
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int K;
    cin >> K;

    vector<int> C(K);
    for(int i = 0; i < K; ++i){
        cin >> C[i];
        --C[i];
    }

    vector<vector<int>> dist(K, vector<int>(N));
    // dist[i][j]: distance from node C[i] to node j
    for(int i = 0; i < K; ++i){
        bfs(C[i], g, dist[i]);
    }

    const int FULL_MASK = (1 << K) - 1;
    vector<vector<int>> minCost(K, vector<int>(FULL_MASK + 1, INF));
    // minCost[i][mask]: min cost at node C[i] when all nodes from `mask` are visited
    //                   jth bit from `mask` represents node C[j]
    //                   cost represents the number of edges (not nodes/vertices)
    
    for(int i = 0; i < K; ++i){
        minCost[i][1 << i] = 0;
    }

    for(int mask = 1; mask <= FULL_MASK; ++mask){
        for(int i = 0; i < K; ++i){
            if((mask >> i) & 1){
                int prevMask = mask ^ (1 << i);
                for(int j = 0; j < K; ++j){
                    if((prevMask >> j) & 1){
                        minCost[i][mask] = min(minCost[j][prevMask] + dist[j][C[i]], minCost[i][mask]);
                    }
                }
            }
        }
    }

    int answer = INF;
    for(int i = 0; i < K; ++i){
        answer = min(1 + minCost[i][FULL_MASK], answer);
    }

    if(answer == INF){
        answer = -1;
    }

    cout << answer;

    return 0;
}