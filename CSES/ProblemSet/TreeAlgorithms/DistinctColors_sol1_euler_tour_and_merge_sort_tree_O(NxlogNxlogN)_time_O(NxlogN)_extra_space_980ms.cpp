#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

class GraphTraversal{
public:
    static void eulerTour(int parent, int node, vector<int>& eulerNodes, const Graph& G){
        eulerNodes.push_back(node);
        for(int nextNode: G[node]){
            if(nextNode != parent){
                eulerTour(node, nextNode, eulerNodes, G);
                eulerNodes.push_back(node);
            }
        }
    }
};

class MergeSortTree{
private:
    const int N;
    vector<vector<int>> tree;

    void buildTree(int node, int l, int r, const vector<int>& NEXT_INDEX){
        if(l == r){
            tree[node] = {NEXT_INDEX[r]};
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, NEXT_INDEX);
            buildTree(2 * node + 2, mid + 1, r, NEXT_INDEX);
            merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
                  tree[2 * node + 2].begin(), tree[2 * node + 2].end(),
                  back_inserter(tree[node]));
        }
    }

    int countDistinctValues(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), R);
        }
        int mid = (l + r) / 2;
        return countDistinctValues(2 * node + 1, l, mid, L, R) +
               countDistinctValues(2 * node + 2, mid + 1, r, L, R);
    }

public:
    MergeSortTree(const vector<int>& NEXT_INDEX): N(NEXT_INDEX.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        buildTree(0, 0, N - 1, NEXT_INDEX);
    }

    int countDistinctValues(const int L, const int R){
        if(L > R){
            return 0;
        }
        return countDistinctValues(0, 0, N - 1, L, R);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read and build Graph G (G is a tree)
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

    // Euler Tour of G
    vector<int> eulerNodes;
    GraphTraversal::eulerTour(-1, 0, eulerNodes, G);

    // Compute first and last index of each node in the eulerNodes vector
    vector<int> firstIndexOfNode(N, -1);
    vector<int> lastIndexOfNode(N);
    for(int i = 0; i < (int)eulerNodes.size(); ++i){
        int node = eulerNodes[i];
        if(firstIndexOfNode[node] == -1){
            firstIndexOfNode[node] = i;
        }
        lastIndexOfNode[node] = i;
    }

    // Compute for each color[eulerNodes[i]] its next index in the eulerNodes vector
    map<int, int> prevIndexOfColor;
    vector<int> nextIndex(eulerNodes.size(), eulerNodes.size());
    for(int i = 0; i < (int)eulerNodes.size(); ++i){
        int color = C[eulerNodes[i]];
        if(prevIndexOfColor.count(color)){
            nextIndex[prevIndexOfColor[color]] = i;
        }
        prevIndexOfColor[color] = i;
    }

    // Build a MergeSortTree on the nextIndex vector and use it to compute the result vector
    vector<int> res(N);
    MergeSortTree tree(nextIndex);
    for(int node = 0; node < N; ++node){
        res[node] = tree.countDistinctValues(firstIndexOfNode[node], lastIndexOfNode[node]);
    }

    for(int node = 0; node < N; ++node){
        cout << res[node] << " ";
    }

    return 0;
}