class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
    const long long INF = 1e18;
    vector<long long> minCost;

    vector<int> topSort(const Graph& G){
        const int N = G.size();

        vector<int> inDegree(N);
        for(int node = 0; node < N; ++node){
            for(auto [nextNode, _]: G[node]){
                inDegree[nextNode] += 1;
            }
        }

        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        vector<int> topOrder;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            topOrder.push_back(node);

            for(auto [nextNode, _]: G[node]){
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }

        return topOrder;
    }

    bool isValidPath(const Graph& G, vector<int>& topOrder, int src, int dest, int costThreshold, long long k){
        const int N = G.size();

        minCost.assign(N, INF);
        minCost[src] = 0;

        for(int node: topOrder){
            for(auto [nextNode, edgeCost]: G[node]){
                long long nextNodeCost = minCost[node] + edgeCost;
                if(edgeCost >= costThreshold && nextNodeCost <= k){
                    minCost[nextNode] = min(minCost[nextNode], nextNodeCost);
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

        vector<int> topOrder = topSort(G);

        int l = -1;
        int r = maxEdgeCost;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValidPath(G, topOrder, 0, N - 1, mid, k)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};