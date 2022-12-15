class Solution {
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
        
        // BFS
        int minScore = INT_MAX;
        vector<bool> vis(N + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(const pair<int, int>& P: G[node]){
                int cost = P.first;
                int nextNode = P.second;
                
                minScore = min(minScore, cost);

                if(!vis[nextNode]){
                    vis[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }

        return minScore;
    }
};