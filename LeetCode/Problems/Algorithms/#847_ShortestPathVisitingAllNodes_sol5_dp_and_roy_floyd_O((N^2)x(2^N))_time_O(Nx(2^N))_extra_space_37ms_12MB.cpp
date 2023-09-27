class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int N = graph.size();
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e9;

        // Step 1: Roy-Floyd algorithm
        //         minCost[a][b]: min cost (i.e., number of edges) from node a to node b
        vector<vector<int>> minCost(N, vector<int>(N, INF));
        for(int node = 0; node < N; ++node){
            for(int nextNode: graph[node]){
                minCost[node][nextNode] = 1;
            }
        }

        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }

        // Step 2: dp on exponential states
        //         dp[a][mask]: min cost (i.e., number of edges) to visit all nodes from bitmask mask
        //                      when a is the last visited node
        vector<vector<int>> dp(N, vector<int>(FULL_MASK + 1, INF));
        for(int bit = 0; bit < N; ++bit){
            dp[bit][1 << bit] = 0;
        }

        for(int mask = 1; mask < FULL_MASK; ++mask){
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    for(int nextBit = 0; nextBit < N; ++nextBit){
                        if(!((mask >> nextBit) & 1)){
                            int nextMask = mask | (1 << nextBit);
                            dp[nextBit][nextMask] = min(dp[nextBit][nextMask], dp[bit][mask] + minCost[bit][nextBit]);
                        }
                    }
                }
            }
        }

        int res = INF;
        for(int bit = 0; bit < N; ++bit){
            res = min(res, dp[bit][FULL_MASK]);
        }

        return res;
    }
};