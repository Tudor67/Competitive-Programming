#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

void dfs(int parent, int node, const vector<int>& C, const Graph& G,
         vector<set<int>>& subtreeColorSet, vector<int>& res){
    for(int nextNode: G[node]){
        if(nextNode != parent){
            dfs(node, nextNode, C, G, subtreeColorSet, res);
            if(subtreeColorSet[node].size() < subtreeColorSet[nextNode].size()){
                swap(subtreeColorSet[node], subtreeColorSet[nextNode]);
            }
            subtreeColorSet[node].insert(subtreeColorSet[nextNode].begin(),
                                         subtreeColorSet[nextNode].end());
            subtreeColorSet[nextNode].clear();
        }
    }
    subtreeColorSet[node].insert(C[node]);
    res[node] = subtreeColorSet[node].size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> C(N);
    for(int i = 0; i < N; ++i){
        cin >> C[i];
    }

    Graph G(N);
    for(int i = 1; i <= N - 1; ++i){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<set<int>> subtreeColorSet(N);
    vector<int> res(N);
    dfs(-1, 0, C, G, subtreeColorSet, res);

    for(int node = 0; node < N; ++node){
        cout << res[node] << " ";
    }

    return 0;
}