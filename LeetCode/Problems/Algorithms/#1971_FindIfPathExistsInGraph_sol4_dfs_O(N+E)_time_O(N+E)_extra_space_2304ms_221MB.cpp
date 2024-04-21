class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, vector<bool>& vis, const Graph& G){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(int nextNode: G[node]){
            dfs(nextNode, vis, G);
        }
    }

public:
    bool validPath(int N, vector<vector<int>>& edges, int source, int destination) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<bool> vis(N, false);
        dfs(source, vis, G);

        return vis[destination];
    }
};