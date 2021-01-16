#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& vis, vector<vector<int>>& g, vector<int>& orderedNodes){
    vis[node] = true;
    orderedNodes.push_back(node);
    for(int nextNode: g[node]){
        if(!vis[nextNode]){
            dfs(nextNode, vis, g, orderedNodes);
        }
    }
    orderedNodes.push_back(node);
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

    int root = -1;
    for(int node = 1; node <= n; ++node){
        if(g[node].size() == 1){
            root = node;
            break;
        }
    }

    vector<int> orderedNodes;
    vector<bool> vis(n + 1, false);
    dfs(root, vis, g, orderedNodes);

    vector<int> inPos(n + 1, -1);
    vector<int> outPos(n + 1, -1);
    for(int i = 0; i < (int)orderedNodes.size(); ++i){
        if(inPos[orderedNodes[i]] == -1){
            inPos[orderedNodes[i]] = i;
        }else{
            outPos[orderedNodes[i]] = i;
        }
    }
    
    int q;
    cin >> q;
    
    vector<long long> mars(orderedNodes.size() + 1, 0);
    for(int i = 1; i <= q; ++i){
        int t, e, x;
        cin >> t >> e >> x;
        int A = a[e];
        int B = b[e];
        if(t == 2){
            swap(A, B);
        }
        if(inPos[A] < inPos[B]){
            mars[0] += x;
            mars[inPos[B]] -= x;
            mars[outPos[B] + 1] += x;
        }else{
            mars[inPos[A]] += x;
            mars[outPos[A] + 1] -= x;
        }
    }

    vector<long long> c(n + 1, 0);
    long long sum = 0;
    for(int i = 0; i < (int)mars.size() - 1; ++i){
        sum += mars[i];
        c[orderedNodes[i]] += sum;
    }

    for(int i = 1; i <= n; ++i){
        cout << c[i] / 2 << "\n";
    }

    return 0;
}