class Solution {
private:
    void dfs(int node, vector<bool>& vis, const vector<vector<int>>& G){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(int nextNode: G[node]){
            dfs(nextNode, vis, G);
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        const int N = stones.size();

        vector<vector<int>> G(N);
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }

        int maxRemovedStones = N;
        vector<bool> vis(N, false);
        for(int i = 0; i < N; ++i){
            if(!vis[i]){
                dfs(i, vis, G);
                maxRemovedStones -= 1;
            }
        }

        return maxRemovedStones;
    }
};