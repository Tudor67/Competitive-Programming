#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using Graph = vector<vector<PII>>;
using MinHeap = priority_queue<PII, vector<PII>, greater<PII>>;
const int INF = 1e9;

// G[node] = {{cost, nextNode}, ... }
// minHeap.top() = {cost, node}

void dijkstra(const int& START_NODE, const Graph& G, vector<vector<int>>& minCost){
    MinHeap minHeap;
    minHeap.push({0, START_NODE});
    minCost[START_NODE][START_NODE] = 0;
    while(!minHeap.empty()){
        int cost = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();
        for(const PII& P: G[node]){
            int nextCost = cost + P.first;
            int nextNode = P.second;
            if(nextCost < minCost[START_NODE][nextNode]){
                minCost[START_NODE][nextNode] = nextCost;
                minHeap.push({nextCost, nextNode});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> answer(N + 1, INF);
    Graph g(N + 1);
    for(int i = 1; i <= M; ++i){
        int A, B, C;
        cin >> A >> B >> C;
        if(A == B){
            answer[A] = min(C, answer[A]);
        }else{
            g[A].push_back({C, B});
        }
    }

    vector<vector<int>> minCost(N + 1, vector<int>(N + 1, INF));
    for(int startNode = 1; startNode <= N; ++startNode){
        dijkstra(startNode, g, minCost);
    }

    for(int node = 1; node <= N; ++node){
        for(const PII& P: g[node]){
            int nextNode = P.second;
            answer[nextNode] = min(minCost[node][nextNode] + minCost[nextNode][node], answer[nextNode]);
        }
    }

    for(int i = 1; i <= N; ++i){
        if(answer[i] == INF){
            cout << "-1" << "\n";
        }else{
            cout << answer[i] << "\n";
        }
    }

    return 0;
}