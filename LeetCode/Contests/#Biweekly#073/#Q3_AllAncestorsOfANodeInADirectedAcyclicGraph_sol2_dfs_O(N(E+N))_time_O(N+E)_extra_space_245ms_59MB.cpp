class Solution {
private:
    void dfs(int node, vector<bool>& vis, const vector<vector<int>>& G){
        if(!vis[node]){
            vis[node] = true;
            for(int nextNode: G[node]){
                dfs(nextNode, vis, G);
            }
        }
    }
    
public:
    vector<vector<int>> getAncestors(int N, vector<vector<int>>& edges) {
        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            G[EDGE[1]].push_back(EDGE[0]);
        }
        
        vector<vector<int>> ancestorsOf(N);
        vector<bool> vis(N);
        
        for(int node = 0; node < N; ++node){
            fill(vis.begin(), vis.end(), false);
            
            dfs(node, vis, G);
            
            vis[node] = false;
            for(int ancestor = 0; ancestor < N; ++ancestor){
                if(vis[ancestor]){
                    ancestorsOf[node].push_back(ancestor);
                }
            }
        }
        
        return ancestorsOf;
    }
};