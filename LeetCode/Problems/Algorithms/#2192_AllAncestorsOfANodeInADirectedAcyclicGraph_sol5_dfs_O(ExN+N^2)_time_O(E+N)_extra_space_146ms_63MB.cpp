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
    vector<vector<int>> getAncestors(int N, vector<vector<int>>& edges) {
        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
        }

        vector<vector<int>> ancestors(N);
        vector<bool> vis(N);
        for(int startNode = 0; startNode < N; ++startNode){
            fill(vis.begin(), vis.end(), false);
            dfs(startNode, vis, G);

            for(int node = 0; node < N; ++node){
                if(vis[node] && node != startNode){
                    ancestors[node].push_back(startNode);
                }
            }
        }

        return ancestors;
    }
};