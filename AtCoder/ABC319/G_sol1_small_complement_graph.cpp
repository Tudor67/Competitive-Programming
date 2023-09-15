#include <bits/stdc++.h>
using namespace std;

const int MODULO = 998244353;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; ++i){
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int node = 0; node < N; ++node){
        sort(G[node].begin(), G[node].end());
    }

    vector<int> dist(N, INF);
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    vector<int> candidates(N - 1);
    iota(candidates.begin(), candidates.end(), 1);

    vector<int> temp;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        temp.clear();
        for(int nextNode: candidates){
            if(binary_search(G[node].begin(), G[node].end(), nextNode)){
                temp.push_back(nextNode);
            }else{
                dist[nextNode] = dist[node] + 1;
                q.push(nextNode);
            }
        }

        candidates = temp;
    }

    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(),
         [&](int lhs, int rhs){
            return dist[lhs] < dist[rhs];
         });

    vector<int> totalCountAtDist(N);
    vector<int> count(N);
    count[0] = 1;
    totalCountAtDist[0] = 1;

    for(int i = 1; i < N && dist[p[i - 1]] + 1 >= dist[p[i]]; ++i){
        int node = p[i];
        count[node] = totalCountAtDist[dist[node] - 1];

        for(int nextNode: G[node]){
            if(dist[nextNode] + 1 == dist[node]){
                count[node] += (MODULO - count[nextNode]);
                count[node] %= MODULO;
            }
        }

        totalCountAtDist[dist[node]] += count[node];
        totalCountAtDist[dist[node]] %= MODULO;
    }

    if(dist[N - 1] == INF){
        cout << -1;
    }else{
        cout << count[N - 1];
    }

    return 0;
}