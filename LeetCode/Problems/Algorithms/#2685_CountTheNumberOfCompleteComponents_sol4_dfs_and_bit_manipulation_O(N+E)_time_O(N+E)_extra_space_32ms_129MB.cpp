class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, vector<bool>& vis, vector<long long>& maskFor, long long& ccAndMask, const Graph& G){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        ccAndMask &= maskFor[node];
        for(int nextNode: G[node]){
            dfs(nextNode, vis, maskFor, ccAndMask, G);
        }
    }

public:
    int countCompleteComponents(int N, vector<vector<int>>& edges) {
        const int E = edges.size();

        Graph G(N);
        vector<long long> maskFor(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
            G[b].push_back(a);
            maskFor[a] |= (1LL << b);
            maskFor[b] |= (1LL << a);
        }

        for(int node = 0; node < N; ++node){
            maskFor[node] |= (1LL << node);
        }

        int completeConnectedComponents = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                long long ccAndMask = maskFor[node];
                dfs(node, vis, maskFor, ccAndMask, G);
                
                if(maskFor[node] == ccAndMask){
                    completeConnectedComponents += 1;
                }
            }
        }

        return completeConnectedComponents;
    }
};