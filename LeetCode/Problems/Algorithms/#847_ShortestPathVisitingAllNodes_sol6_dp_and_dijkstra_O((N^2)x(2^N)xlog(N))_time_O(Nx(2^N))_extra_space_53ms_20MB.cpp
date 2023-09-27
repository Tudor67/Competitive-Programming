class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int N = graph.size();
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e9;

        // Step 1: dp on exponential states (using Dijkstra's Algorithm)
        //         dp[a][mask]: min cost (i.e., number of edges) to visit all nodes from bitmask mask
        //                      when a is the last visited node
        vector<vector<int>> dp(N, vector<int>(FULL_MASK + 1, INF));
        set<tuple<int, int, int>> statesSet;
        for(int node = 0; node < N; ++node){
            dp[node][1 << node] = 0;
            statesSet.insert({dp[node][1 << node], node, 1 << node});
        }

        while(!statesSet.empty()){
            int node = get<1>(*statesSet.begin());
            int mask = get<2>(*statesSet.begin());
            statesSet.erase(statesSet.begin());

            for(int nextNode: graph[node]){
                int nextMask = mask | (1 << nextNode);
                if(dp[node][mask] + 1 < dp[nextNode][nextMask]){
                    statesSet.erase({dp[nextNode][nextMask], nextNode, nextMask});
                    dp[nextNode][nextMask] = dp[node][mask] + 1;
                    statesSet.insert({dp[nextNode][nextMask], nextNode, nextMask});
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