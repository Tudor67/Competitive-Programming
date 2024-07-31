class Solution {
public:
    int findTheCity(int N, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<int>> dist(N, vector<int>(N, INF));
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            dist[a][b] = w;
            dist[b][a] = w;
        }

        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int resNode = N + 1;
        int resNeighCount = N + 1;
        for(int node = 0; node < N; ++node){
            int neighCount = 0;
            for(int nextNode = 0; nextNode < N; ++nextNode){
                if(node != nextNode && dist[node][nextNode] <= distanceThreshold){
                    neighCount += 1;
                }
            }
            if(neighCount <= resNeighCount){
                resNode = node;
                resNeighCount = neighCount;
            }
        }

        return resNode;
    }
};