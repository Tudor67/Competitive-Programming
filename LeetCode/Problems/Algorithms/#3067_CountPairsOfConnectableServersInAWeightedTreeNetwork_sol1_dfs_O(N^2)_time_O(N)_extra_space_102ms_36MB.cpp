class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;

    void dfs(int parent, int node, int pathWeight, int signalSpeed, const Graph& G, int& subtreeGoodNodes){
        if(pathWeight % signalSpeed == 0){
            subtreeGoodNodes += 1;
        }
        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            int w = P.second;
            if(nextNode != parent){
                dfs(node, nextNode, pathWeight + w, signalSpeed, G, subtreeGoodNodes);
            }
        }
    }

public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        const int E = edges.size();
        const int N = E + 1;

        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            G[a].push_back({b, w});
            G[b].push_back({a, w});
        }

        vector<int> res(N);
        for(int root = 0; root < N; ++root){
            int totalGoodNodes = 0;
            for(pair<int, int>& P: G[root]){
                int child = P.first;
                int w = P.second;
                int subtreeGoodNodes = 0;
                dfs(root, child, w, signalSpeed, G, subtreeGoodNodes);
                res[root] += (totalGoodNodes * subtreeGoodNodes);
                totalGoodNodes += subtreeGoodNodes;
            }
        }

        return res;
    }
};