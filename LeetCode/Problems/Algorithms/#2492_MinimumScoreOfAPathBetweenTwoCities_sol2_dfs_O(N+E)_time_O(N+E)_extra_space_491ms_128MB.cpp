class Solution {
private:
    void dfs(int node, vector<bool>& vis, const vector<vector<pair<int, int>>>& G, int& minScore){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(const pair<int, int>& P: G[node]){
            int cost = P.first;
            int nextNode = P.second;
            minScore = min(minScore, cost);
            dfs(nextNode, vis, G, minScore);
        }
    }

public:
    int minScore(int N, vector<vector<int>>& roads) {
        // Graph G
        vector<vector<pair<int, int>>> G(N + 1);
        for(const vector<int>& R: roads){
            int a = R[0];
            int b = R[1];
            int cost = R[2];
            G[a].push_back({cost, b});
            G[b].push_back({cost, a});
        }
        
        // DFS
        int minScore = INT_MAX;
        vector<bool> vis(N + 1, false);
        dfs(1, vis, G, minScore);

        return minScore;
    }
};