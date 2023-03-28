class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int parentNode, int node, const Graph& G, set<pair<int, int>>& connectionsSet, int& reverseEdgeOps){
        for(int childNode: G[node]){
            if(childNode != parentNode){
                if(!connectionsSet.count({childNode, node})){
                    reverseEdgeOps += 1;
                }
                dfs(node, childNode, G, connectionsSet, reverseEdgeOps);
            }
        }
    }

public:
    int minReorder(int N, vector<vector<int>>& connections) {
        Graph G(N);
        set<pair<int, int>> connectionsSet;
        for(const vector<int>& CONNECTION: connections){
            int a = CONNECTION[0];
            int b = CONNECTION[1];
            G[a].push_back(b);
            G[b].push_back(a);
            connectionsSet.insert({a, b});
        }

        int reverseEdgeOps = 0;
        dfs(-1, 0, G, connectionsSet, reverseEdgeOps);

        return reverseEdgeOps;
    }
};