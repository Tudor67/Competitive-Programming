class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;

    void dfs(int node, vector<bool>& vis, int& minEdgeCost, const Graph& G){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(auto [nextNode, edgeCost]: G[node]){
            minEdgeCost = min(minEdgeCost, edgeCost);
            dfs(nextNode, vis, minEdgeCost, G);
        }
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        Graph G(n);
        for(vector<int>& road: roads){
            int a = road[0] - 1;
            int b = road[1] - 1;
            int dist = road[2];
            G[a].push_back({b, dist});
            G[b].push_back({a, dist});
        }

        vector<bool> vis(n, false);
        int minEdgeCost = INT_MAX;
        dfs(0, vis, minEdgeCost, G);

        return minEdgeCost;
    }
};