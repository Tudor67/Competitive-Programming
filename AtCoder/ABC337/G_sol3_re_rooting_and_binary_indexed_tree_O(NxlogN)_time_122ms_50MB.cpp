#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

class BinaryIndexedTree{
private:
    const int N;
    vector<int> tree;

    static int nonZeroLSB(int x){
        return x - (x & (x - 1));
    }

public:
    BinaryIndexedTree(const int N): N(N){
        tree.resize(N);
    }

    void add(const int POS, const int VAL){
        for(int i = POS; i < N; i += nonZeroLSB(i)){
            tree[i] += VAL;
        }
    }

    int getPrefixSum(const int POS){
        int prefixSum = 0;
        for(int i = POS; i >= 1; i -= nonZeroLSB(i)){
            prefixSum += tree[i];
        }
        return prefixSum;
    }
};

void dfs1(int parent, int node, const Graph& G, vector<long long>& f,
          vector<int>& lp, vector<int>& lr,
          BinaryIndexedTree& tree, vector<int>& lpIn, vector<int>& lrIn){
    lpIn[node] = tree.getPrefixSum(parent);
    lrIn[node] = tree.getPrefixSum(node);

    for(int nextNode: G[node]){
        if(nextNode != parent){
            dfs1(node, nextNode, G, f, lp, lr, tree, lpIn, lrIn);
            f[node] += f[nextNode];
        }
    }
    
    tree.add(node + 1, 1);
    lp[node] = tree.getPrefixSum(parent) - lpIn[node];
    lr[node] = tree.getPrefixSum(node) - lrIn[node];

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
    vector<int> lp(N + 1);
    vector<int> lr(N + 1);
    BinaryIndexedTree tree(N + 2);
    vector<int> lpIn(N + 1);
    vector<int> lrIn(N + 1);
    dfs1(-1, FIXED_ROOT, G, f, lp, lr, tree, lpIn, lrIn);

    dfs2(-1, FIXED_ROOT, G, f, lp, lr);

    for(int node = 1; node <= N; ++node){
        cout << f[node] << " ";
    }

    return 0;
}