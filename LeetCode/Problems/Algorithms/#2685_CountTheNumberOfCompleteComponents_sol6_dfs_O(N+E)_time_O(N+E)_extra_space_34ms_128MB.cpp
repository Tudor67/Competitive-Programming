class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, vector<bool>& vis, int& ccNodes, int& ccEdges, const Graph& G){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        ccNodes += 1;
        for(int nextNode: G[node]){
            ccEdges += 1;
            dfs(nextNode, vis, ccNodes, ccEdges, G);
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Graph G(n);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int completeComponents = 0;
        vector<bool> vis(n);
        for(int node = 0; node < n; ++node){
            if(!vis[node]){
                int ccNodes = 0;
                int ccEdges = 0;
                dfs(node, vis, ccNodes, ccEdges, G);
                if((ccNodes - 1) * ccNodes == ccEdges){
                    completeComponents += 1;
                }
            }
        }

        return completeComponents;
    }
};