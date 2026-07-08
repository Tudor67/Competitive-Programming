class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
    const long long INF = 1e18;
    vector<long long> minCost;

    bool isValidPath(const Graph& G, int src, int dest, int costThreshold, long long k){
        const int N = G.size();

        set<pair<long long, int>> statesSet;

        minCost.assign(N, INF);
        minCost[src] = 0;
        statesSet.insert({minCost[src], src});

        while(!statesSet.empty() && minCost[dest] > k){
            int node = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());

            for(auto [nextNode, edgeCost]: G[node]){
                long long nextCost = minCost[node] + edgeCost;
                if(edgeCost >= costThreshold && nextCost <= k && minCost[nextNode] > nextCost){
                    statesSet.erase({minCost[nextNode], nextNode});
                    minCost[nextNode] = nextCost;
                    statesSet.insert({minCost[nextNode], nextNode});
                }
            }
        }

        return (minCost[dest] <= k);
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        const int N = online.size();

        Graph G(N);
        int maxEdgeCost = 0;
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            int cost = edge[2];
            if(online[a] && online[b]){
                G[a].push_back({b, cost});
                maxEdgeCost = max(maxEdgeCost, cost);
            }
        }

        int l = 0;
        int r = maxEdgeCost;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValidPath(G, 0, N - 1, mid, k)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        if(isValidPath(G, 0, N - 1, r, k)){
            return r;
        }

        return -1;
    }
};