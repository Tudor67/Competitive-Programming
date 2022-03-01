class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int N = graph.size();
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e8;
        
        // dist[i][j]: min distance (num of edges) between nodes i and j
        vector<vector<int>> dist(N, vector<int>(N, INF));
        
        for(int i = 0; i < N; ++i){
            for(int j: graph[i]){
                dist[i][j] = 1;
            }
            dist[i][i] = 0;
        }
        
        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        // dp[i][mask]: min cost to visit all nodes from bitmask `mask`
        //              when the last visited node is `i`
        vector<vector<int>> dp(N, vector<int>(FULL_MASK + 1, INF));
        
        for(int i = 0; i < N; ++i){
            dp[i][1 << i] = 0;
        }
        
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            for(int i = 0; i < N; ++i){
                if((mask >> i) & 1){
                    for(int j = 0; j < N; ++j){
                        if(!((mask >> j) & 1)){
                            int nextMask = mask | (1 << j);
                            dp[j][nextMask] = min(dp[j][nextMask], dp[i][mask] + dist[i][j]);
                        }
                    }
                }
            }
        }
        
        int res = INF;
        for(int i = 0; i < N; ++i){
            res = min(res, dp[i][FULL_MASK]);
        }
        
        return res;
    }
};