class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;

    void dfs(int node, int cc, vector<int>& ccOf, vector<int>& maskOf, const Graph& G){
        if(ccOf[node] >= 0){
            return;
        }
        ccOf[node] = cc;
        for(auto& [nextNode, w]: G[node]){
            maskOf[cc] &= w;
            dfs(nextNode, cc, ccOf, maskOf, G);
        }
    }

public:
    vector<int> minimumCost(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        const int E = edges.size();
        const int Q = queries.size();
        const int FULL_MASK = (1 << 30) - 1;

        Graph G(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            int w = edge[2];
            G[a].push_back({b, w});
            G[b].push_back({a, w});
        }

        int cc = -1;
        vector<int> ccOf(N, -1);
        vector<int> maskOf(N, FULL_MASK);
        for(int node = 0; node < N; ++node){
            if(ccOf[node] == -1){
                cc += 1;
                dfs(node, cc, ccOf, maskOf, G);
            }
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];

            if(ccOf[a] == ccOf[b]){
                res[i] = maskOf[ccOf[a]];
            }else{
                res[i] = -1;
            }
        }

        return res;
    }
};