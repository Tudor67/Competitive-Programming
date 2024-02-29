class Solution {
public:
    int findCheapestPrice(int N, vector<vector<int>>& flights, int src, int dest, int k) {
        const int INF = 1e9;

        vector<int> prevDist(N, INF);
        vector<int> dist(N, INF);
        prevDist[src] = 0;

        for(int steps = 1; steps <= k + 1; ++steps){
            for(const vector<int>& F: flights){
                int a = F[0];
                int b = F[1];
                int cost = F[2];
                dist[b] = min(dist[b], prevDist[a] + cost);
            }
            if(prevDist == dist){
                break;
            }
            prevDist = dist;
        }

        if(dist[dest] == INF){
            dist[dest] = -1;
        }

        return dist[dest];
    }
};