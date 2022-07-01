class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
    const int INF = INT_MAX;
    const int MODULO = 1e9 + 7;

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
        //         for bottom-up dp we need to process the nodes in decreasing order of their distanceToLastNode
        vector<pair<int, int>> distNode(N);
        for(int i = 0; i < N; ++i){
            distNode[i] = {distanceToLastNode[i], i};
        }
        
        sort(distNode.rbegin(), distNode.rend());
        
        // dp[x]: the number of restricted paths from node 0 to node x
        vector<int> dp(N);
        dp[0] = 1;
        for(int i = 0; i < N; ++i){
            int node = distNode[i].second;
            for(const pair<int, int>& P: G[node]){
                int nextNode = P.second;
                if(distanceToLastNode[node] > distanceToLastNode[nextNode]){
                    dp[nextNode] += dp[node];
                    dp[nextNode] %= MODULO;
                }
            }
        }
        
        return dp[N - 1];
    }
};