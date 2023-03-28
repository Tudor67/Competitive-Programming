class Solution {
private:
    using Graph = vector<vector<pair<int, bool>>>;

    void dfs(int parentNode, int node, const Graph& G, int& reverseEdgeOps){
        for(const pair<int, int>& P: G[node]){
            int childNode = P.first;
            bool isOriginalDirection = P.second;
            if(childNode != parentNode){
                if(isOriginalDirection){
                    reverseEdgeOps += 1;
                }
                dfs(node, childNode, G, reverseEdgeOps);
            }
        }
    }

public:
    int minReorder(int N, vector<vector<int>>& connections) {
        Graph G(N);
        for(const vector<int>& CONNECTION: connections){
            int a = CONNECTION[0];
            int b = CONNECTION[1];
            G[a].push_back({b, true});
            G[b].push_back({a, false});
        }

        int reverseEdgeOps = 0;
        dfs(-1, 0, G, reverseEdgeOps);

        return reverseEdgeOps;
    }
};