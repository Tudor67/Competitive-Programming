class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int N = graph.size();
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e8;
        
        // cost[i][j]: length of the shortest path between node i and node j
        vector<vector<int>> cost(N, vector<int>(N, INF));
        for(int node = 0; node < N; ++node){
            for(int nextNode: graph[node]){
                cost[node][nextNode] = 1;
                cost[nextNode][node] = 1;
            }
        }
        
        // Roy-Floyd algorithm for finding the shortest paths between any two nodes
        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
        
        // dp[mask][i]: length of the shortest path which visits nodes from mask
        //              and the ith node is the last visited node
        vector<vector<int>> dp(FULL_MASK + 1, vector<int>(N, INF));
        for(int node = 0; node < N; ++node){
            dp[1 << node][node] = 0;
        }
        
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            for(int node = 0; node < N; ++node){
                if((mask >> node) & 1){
                    int prevMask = mask - (1 << node);
                    for(int prevNode = 0; prevNode < N; ++prevNode){
                        if((prevMask >> prevNode) & 1){
                            dp[mask][node] = min(dp[mask][node], dp[prevMask][prevNode] + cost[prevNode][node]);
                        }
                    }
                }
            }
        }
        
        return *min_element(dp[FULL_MASK].begin(), dp[FULL_MASK].end());
    }
};