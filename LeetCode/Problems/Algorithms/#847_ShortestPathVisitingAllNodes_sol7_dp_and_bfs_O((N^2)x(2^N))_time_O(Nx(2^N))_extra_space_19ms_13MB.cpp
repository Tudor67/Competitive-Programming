class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int N = graph.size();
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e9;

        // Step 1: dp on exponential states
        //         dp[a][mask]: min cost (i.e., number of edges) to visit all nodes from bitmask mask
        //                      when a is the last visited node
        vector<vector<int>> dp(N, vector<int>(FULL_MASK + 1, INF));
        queue<pair<int, int>> statesQueue;
        for(int node = 0; node < N; ++node){
            dp[node][1 << node] = 0;
            statesQueue.push({node, 1 << node});
        }

        while(!statesQueue.empty()){
            int node = statesQueue.front().first;
            int mask = statesQueue.front().second;
            statesQueue.pop();

            if(mask == FULL_MASK){
                return dp[node][mask];
            }

            for(int nextNode: graph[node]){
                int nextMask = mask | (1 << nextNode);
                if(dp[node][mask] + 1 < dp[nextNode][nextMask]){
                    dp[nextNode][nextMask] = dp[node][mask] + 1;
                    statesQueue.push({nextNode, nextMask});
                }
            }
        }

        return -1;
    }
};