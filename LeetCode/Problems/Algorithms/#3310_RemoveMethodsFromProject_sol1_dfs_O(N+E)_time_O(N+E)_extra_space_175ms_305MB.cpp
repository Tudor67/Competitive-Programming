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
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        Graph G(n);
        for(vector<int>& inv: invocations){
            G[inv[0]].push_back(inv[1]);
        }

        vector<bool> vis(n);
        dfs(k, vis, G);

        bool canRemove = true;
        for(int node = 0; node < n; ++node){
            for(int nextNode: G[node]){
                if(!vis[node] && vis[nextNode]){
                    canRemove = false;
                }
            }
        }

        vector<int> res;
        if(canRemove){
            for(int node = 0; node < n; ++node){
                if(!vis[node]){
                    res.push_back(node);
                }
            }
        }else{
            for(int node = 0; node < n; ++node){
                res.push_back(node);
            }
        }

        return res;
    }
};