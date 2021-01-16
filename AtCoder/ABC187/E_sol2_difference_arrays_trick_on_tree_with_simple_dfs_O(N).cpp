#include <bits/stdc++.h>
using namespace std;

void bfs(const int& ROOT, vector<vector<int>>& g, vector<int>& distToRoot){
    fill(distToRoot.begin(), distToRoot.end(), -1);
    distToRoot[ROOT] = 0;
    queue<int> q;
    q.push(ROOT);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int nextNode: g[node]){
            if(distToRoot[nextNode] == -1){
                q.push(nextNode);
                distToRoot[nextNode] = 1 + distToRoot[node];
            }
        }
    }
}

void dfs(int node, long long currentWeight, vector<bool>& vis, vector<long long>& w,
         vector<long long>& c, vector<vector<int>>& g){
    vis[node] = true;
    c[node] += currentWeight;
    for(int nextNode: g[node]){
        if(!vis[nextNode]){
            dfs(nextNode, currentWeight + w[nextNode], vis, w, c, g);
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 1; i <= n - 1; ++i){
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    int root = 1;
    vector<int> distToRoot(n + 1);
    bfs(root, g, distToRoot);

    int q;
    cin >> q;
    
    vector<long long> w(n + 1, 0);
    for(int i = 1; i <= q; ++i){
        int t, e, x;
        cin >> t >> e >> x;
        int A = a[e];
        int B = b[e];
        if(t == 2){
            swap(A, B);
        }
        if(distToRoot[A] < distToRoot[B]){
            w[root] += x;
            w[B] -= x;
        }else{
            w[A] += x;
        }
    }

    vector<bool> vis(n + 1, false);
    vector<long long> c(n + 1, 0);
    dfs(root, w[root], vis, w, c, g);

    for(int i = 1; i <= n; ++i){
        cout << c[i] << "\n";
    }

    return 0;
}