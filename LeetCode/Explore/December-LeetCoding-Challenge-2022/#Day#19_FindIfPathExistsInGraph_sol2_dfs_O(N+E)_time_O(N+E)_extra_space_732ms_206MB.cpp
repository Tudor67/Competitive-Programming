class Solution {
private:
    void dfs(int node, vector<bool>& vis, const vector<vector<int>>& G){
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
        vector<vector<int>> G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<bool> vis(N, false);
        dfs(source, vis, G);

        return vis[destination];
    }
};