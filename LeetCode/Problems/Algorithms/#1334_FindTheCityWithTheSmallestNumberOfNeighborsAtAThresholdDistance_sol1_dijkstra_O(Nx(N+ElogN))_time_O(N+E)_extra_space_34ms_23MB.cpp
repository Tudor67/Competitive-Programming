class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;

    int countReachableNeighbors(int srcNode, const Graph& G, int distanceThreshold){
        const int N = G.size();
        const int INF = 1e9;

        vector<int> dist(N, INF);
        set<pair<int, int>> statesSet;
        dist[srcNode] = 0;
        statesSet.insert({dist[srcNode], srcNode});

        while(!statesSet.empty()){
            int node = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());

            for(const pair<int, int>& P: G[node]){
                int w = P.first;
                int nextNode = P.second;
                if(dist[node] + w <= distanceThreshold && dist[node] + w < dist[nextNode]){
                    statesSet.erase({dist[nextNode], nextNode});
                    dist[nextNode] = dist[node] + w;
                    statesSet.insert({dist[nextNode], nextNode});
                }
            }
        }

        int reachableNeighbors = 0;
        for(int node = 0; node < N; ++node){
            if(node != srcNode && dist[node] <= distanceThreshold){
                reachableNeighbors += 1;
            }
        }

        return reachableNeighbors;
    }

public:
    int findTheCity(int N, vector<vector<int>>& edges, int distanceThreshold) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            G[a].push_back({w, b});
            G[b].push_back({w, a});
        }

        int resNode = N + 1;
        int resNeighCount = N + 1;
        for(int srcNode = 0; srcNode < N; ++srcNode){
            int neighCount = countReachableNeighbors(srcNode, G, distanceThreshold);
            if(neighCount <= resNeighCount){
                resNode = srcNode;
                resNeighCount = neighCount;
            }
        }

        return resNode;
    }
};