class Solution {
private:
    using Graph = vector<vector<int>>;

    int computeMaxDepth(int parent, int node, const Graph& G){
        int maxDepth = 0;
        for(int child: G[node]){
            if(child != parent){
                maxDepth = max(maxDepth, 1 + computeMaxDepth(node, child, G));
            }
        }
        return maxDepth;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int E = edges.size();
        const int N = E + 1;
        const int MODULO = 1'000'000'007;

        Graph G(N + 1);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int maxDepth = computeMaxDepth(-1, 1, G);

        int oddWays = 1;
        for(int i = 1; i <= maxDepth - 1; ++i){
            oddWays *= 2;
            oddWays %= MODULO;
        }

        return oddWays;
    }
};