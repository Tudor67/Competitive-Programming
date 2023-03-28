class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, vector<bool>& vis, const Graph& G, int& ccSize){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        ccSize += 1;
        for(int nextNode: G[node]){
            dfs(nextNode, vis, G, ccSize);
        }
    }

public:
    long long countPairs(int N, vector<vector<int>>& edges) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        long long res = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                int ccSize = 0;
                dfs(node, vis, G, ccSize);
                res += ccSize * 1LL * (N - ccSize);
            }
        }

        return res / 2;
    }
};