class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;

    void dfs(int node, vector<bool>& vis, const Graph& G, int& res){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            int distance = P.second;
            res = min(res, distance);
            dfs(nextNode, vis, G, res);
        }
    }

public:
    int minScore(int N, vector<vector<int>>& roads) {
        Graph G(N + 1);
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            int distance = ROAD[2];
            G[a].push_back({b, distance});
            G[b].push_back({a, distance});
        }

        vector<bool> vis(N + 1, false);
        int res = G[1][0].second;
        dfs(1, vis, G, res);

        return res;
    }
};