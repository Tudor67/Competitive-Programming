class Solution {
private:
    struct PairHash{
        size_t operator()(const pair<int, int>& P) const{
            size_t first = P.first;
            size_t second = P.second;
            return (first << 16) | second;
        }
    };
    using Graph = vector<vector<int>>;
    using HashSet = unordered_set<pair<int, int>, PairHash>;

    void dfs(int parentNode, int node, const Graph& G, HashSet& connectionsSet, int& reverseEdgeOps){
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
        HashSet connectionsSet;
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