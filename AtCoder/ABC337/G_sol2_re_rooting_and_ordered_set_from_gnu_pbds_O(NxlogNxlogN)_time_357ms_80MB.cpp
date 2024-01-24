#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using Graph = vector<vector<int>>;

void dfs1(int parent, int node, const Graph& G, vector<long long>& f,
          vector<ordered_set<int>>& subtreeValues, vector<int>& lp, vector<int>& lr){
    for(int nextNode: G[node]){
        if(nextNode != parent){
            dfs1(node, nextNode, G, f, subtreeValues, lp, lr);
            f[node] += f[nextNode];
            
            if(subtreeValues[node].size() < subtreeValues[nextNode].size()){
                subtreeValues[node].swap(subtreeValues[nextNode]);
            }
            for(int val: subtreeValues[nextNode]){
                subtreeValues[node].insert(val);
            }
            subtreeValues[nextNode].clear();
        }
    }
    
    subtreeValues[node].insert(node);
    lp[node] = subtreeValues[node].order_of_key(parent);
    lr[node] = subtreeValues[node].order_of_key(node);
    
    f[node] += lr[node];
}

void dfs2(int parent, int node, const Graph& G, vector<long long>& f,
          vector<int>& lp, vector<int>& lr){
    if(parent != -1){
        f[node] = f[node] + node - 1 - lr[node] +
                  f[parent] - f[node] - lp[node];
    }
    for(int nextNode: G[node]){
        if(nextNode != parent){
            dfs2(node, nextNode, G, f, lp, lr);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Graph G(N + 1);
    for(int i = 1; i <= N - 1; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    const int FIXED_ROOT = 1;
    vector<long long> f(N + 1);
    vector<ordered_set<int>> subtreeValues(N + 1);
    vector<int> lp(N + 1);
    vector<int> lr(N + 1);
    dfs1(-1, FIXED_ROOT, G, f, subtreeValues, lp, lr);

    dfs2(-1, FIXED_ROOT, G, f, lp, lr);

    for(int node = 1; node <= N; ++node){
        cout << f[node] << " ";
    }

    return 0;
}