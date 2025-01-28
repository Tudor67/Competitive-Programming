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
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        const int N = numCourses;
        const int Q = queries.size();

        Graph G(N);
        for(const vector<int>& P: prerequisites){
            int a = P[0];
            int b = P[1];
            G[a].push_back(b);
        }

        vector<vector<bool>> isReachable(N, vector<bool>(N, false));
        for(int node = 0; node < N; ++node){
            dfs(node, isReachable[node], G);
        }

        vector<bool> res(Q);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];
            res[i] = isReachable[a][b];
        }

        return res;
    }
};