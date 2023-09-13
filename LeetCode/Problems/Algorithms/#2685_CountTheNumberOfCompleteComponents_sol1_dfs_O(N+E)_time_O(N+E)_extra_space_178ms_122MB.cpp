class Solution {
private:
    using Graph = vector<vector<int>>;
    
    void dfs(int node, vector<bool>& vis, const Graph& G, int& visNodes, int& visEdges){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        visNodes += 1;
        visEdges += G[node].size();
        for(int nextNode: G[node]){
            dfs(nextNode, vis, G, visNodes, visEdges);
        }
    }
    
public:
    int countCompleteComponents(int N, vector<vector<int>>& edges) {
        Graph G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        int completeCC = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                int visNodes = 0;
                int visEdges = 0;
                dfs(node, vis, G, visNodes, visEdges);
                
                if(visNodes * (visNodes - 1) == visEdges){
                    completeCC += 1;
                }
            }
        }
        
        return completeCC;
    }
};