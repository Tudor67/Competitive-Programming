class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
    const int INF = INT_MAX;
    const int MODULO = 1e9 + 7;
    
    void dfs(int node, const Graph& G, vector<int>& distanceToLastNode, vector<int>& dp){
        if(dp[node] != INF){
            return;
        }else if(node == 0){
            dp[node] = 1;
        }else{
            dp[node] = 0;
            for(const pair<int, int>& P: G[node]){
                int nextNode = P.second;
                if(distanceToLastNode[node] < distanceToLastNode[nextNode]){
                    dfs(nextNode, G, distanceToLastNode, dp);
                    dp[node] += dp[nextNode];
                    dp[node] %= MODULO;
                }
            }
        }
    }
    
public:
    int countRestrictedPaths(int N, vector<vector<int>>& edges) {
        // Step 1: create Graph G (shift nodes [1 .. N] to nodes [0 .. N - 1])
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0];
            int y = EDGE[1];
            int w = EDGE[2];
            G[x - 1].emplace_back(w, y - 1);
            G[y - 1].emplace_back(w, x - 1);
        }
        
        // Step 2: use Dijkstra's algorithm to compute distanceToLastNode[node]
        vector<int> distanceToLastNode(N, INF);
        set<pair<int, int>> stateSet;
        distanceToLastNode[N - 1] = 0;
        stateSet.emplace(distanceToLastNode[N - 1], N - 1);
        
        while(!stateSet.empty()){
            int node = stateSet.begin()->second;
            stateSet.erase(stateSet.begin());
            
            for(const pair<int, int>& P: G[node]){
                int w = P.first;
                int nextNode = P.second;
                if(distanceToLastNode[node] + w < distanceToLastNode[nextNode]){
                    stateSet.erase({distanceToLastNode[nextNode], nextNode});
                    distanceToLastNode[nextNode] = distanceToLastNode[node] + w;
                    stateSet.emplace(distanceToLastNode[nextNode], nextNode);
                }
            }
        }
        
        // Step 3: apply DP to compute the number of restricted paths from node 0 to node N - 1
        // dp[x]: the number of restricted paths from node 0 to node x
        vector<int> dp(N, INF);
        dfs(N - 1, G, distanceToLastNode, dp);
        
        return dp[N - 1];
    }
};