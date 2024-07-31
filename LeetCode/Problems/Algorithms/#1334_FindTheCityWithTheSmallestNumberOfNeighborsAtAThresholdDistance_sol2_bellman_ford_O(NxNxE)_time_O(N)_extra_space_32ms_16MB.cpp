class Solution {
private:
    int countReachableNeighbors(int srcNode, const int N, vector<vector<int>>& edges, int distanceThreshold){
        const int INF = 1e9;

        vector<int> dist(N, INF);
        dist[srcNode] = 0;

        bool updated = true;
        while(updated){
            updated = false;
            for(const vector<int>& EDGE: edges){
                int a = EDGE[0];
                int b = EDGE[1];
                int w = EDGE[2];
                if(dist[b] > dist[a] + w){
                    dist[b] = dist[a] + w;
                    updated = true;
                }
                if(dist[a] > dist[b] + w){
                    dist[a] = dist[b] + w;
                    updated = true;
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
        int resNode = N + 1;
        int resNeighCount = N + 1;
        for(int srcNode = 0; srcNode < N; ++srcNode){
            int neighCount = countReachableNeighbors(srcNode, N, edges, distanceThreshold);
            if(neighCount <= resNeighCount){
                resNode = srcNode;
                resNeighCount = neighCount;
            }
        }
        return resNode;
    }
};