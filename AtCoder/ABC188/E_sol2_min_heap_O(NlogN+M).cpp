#include <bits/stdc++.h>
using namespace std;

using MinHeap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
using Graph = vector<vector<int>>;

int bfs(const int& SRC_NODE, vector<bool>& vis, Graph& g, vector<int>& a){
    int nextNodeMaxPrice = INT_MIN;
    queue<int> q;
    q.push(SRC_NODE);
    vis[SRC_NODE] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int nextNode: g[node]){
            if(!vis[nextNode]){
                q.push(nextNode);
                vis[nextNode] = true;
            }
            nextNodeMaxPrice = max(a[nextNode], nextNodeMaxPrice);
        }
    }
    return nextNodeMaxPrice;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    MinHeap minHeap;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        minHeap.push({a[i], i});
    }

    Graph g(n + 1);
    int x, y;
    for(int i = 1; i <= m; ++i){
        cin >> x >> y;
        g[x].push_back(y);
    }

    int answer = INT_MIN;
    vector<bool> vis(n + 1, false);
    while(!minHeap.empty()){
        int nodePrice = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();

        int nextNodeMaxPrice = bfs(node, vis, g, a);
        if(nextNodeMaxPrice != INT_MIN){
            answer = max(nextNodeMaxPrice - nodePrice, answer);
        }
    }

    cout << answer;

    return 0;
}