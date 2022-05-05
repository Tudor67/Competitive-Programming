class Solution {
private:
    void dfs(int ancestor, int node, vector<bool>& vis, const vector<vector<int>>& G, vector<vector<int>>& ancestorsOf){
        if(!vis[node]){
            vis[node] = true;
            if(ancestor != node){
                ancestorsOf[node].push_back(ancestor);
            }
            for(int nextNode: G[node]){
                dfs(ancestor, nextNode, vis, G, ancestorsOf);
            }
        }
    }
    
public:
    vector<vector<int>> getAncestors(int N, vector<vector<int>>& edges) {
        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            G[EDGE[0]].push_back(EDGE[1]);
        }
        
        vector<vector<int>> ancestorsOf(N);
        vector<bool> vis(N);
        for(int node = 0; node < N; ++node){
            fill(vis.begin(), vis.end(), false);
            dfs(node, node, vis, G, ancestorsOf);
        }
        
        return ancestorsOf;
    }
};