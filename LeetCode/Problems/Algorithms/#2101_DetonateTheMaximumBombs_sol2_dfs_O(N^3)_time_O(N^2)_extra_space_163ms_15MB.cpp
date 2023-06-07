class Solution {
private:
    using Graph = vector<vector<int>>;

    long long computeSquareDistance(const vector<int>& A, const vector<int>& B){
        long long dx = A[0] - B[0];
        long long dy = A[1] - B[1];
        return dx * dx + dy * dy;
    }

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
    int maximumDetonation(vector<vector<int>>& bombs) {
        const int N = bombs.size();

        Graph G(N);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j){
                    long long ri = bombs[i][2];
                    if(computeSquareDistance(bombs[i], bombs[j]) <= ri * ri){
                        G[i].push_back(j);
                    }
                }
            }
        }

        int res = 0;
        vector<bool> vis(N);
        for(int node = 0; node < N; ++node){
            fill(vis.begin(), vis.end(), false);
            dfs(node, vis, G);

            int visNodesCount = count(vis.begin(), vis.end(), true);
            res = max(res, visNodesCount);
        }

        return res;
    }
};