#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

void dfs(int parent, int node, const Graph& G, vector<int>& subtreeSize){
    if(subtreeSize[node] != 0){
        return;
    }
    subtreeSize[node] = 1;
    for(int nextNode: G[node]){
        if(nextNode != parent){
            dfs(node, nextNode, G, subtreeSize);
            subtreeSize[node] += subtreeSize[nextNode];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Graph G(N);
    for(int i = 1; i <= N - 1; ++i){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> subtreeSize(N);
    dfs(-1, 0, G, subtreeSize);

    int res = 1;
    int subtreeMaxSize = 0;
    for(int child: G[0]){
        res += subtreeSize[child];
        subtreeMaxSize = max(subtreeMaxSize, subtreeSize[child]);
    }

    res -= subtreeMaxSize;

    cout << res;

    return 0;
}