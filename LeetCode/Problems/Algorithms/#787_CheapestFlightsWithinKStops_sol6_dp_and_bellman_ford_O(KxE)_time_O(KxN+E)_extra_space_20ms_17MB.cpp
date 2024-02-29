class Solution {
public:
    int findCheapestPrice(int N, vector<vector<int>>& flights, int src, int dest, int k) {
        const int INF = 1e9;
        
        vector<vector<pair<int, int>>> G(N);
        for(const vector<int>& F: flights){
            int a = F[0];
            int b = F[1];
            int cost = F[2];
            G[a].push_back({b, cost});
        }

        // dist[x][dest]: min cost from src to dest when we use (x - 1) stops
        vector<vector<int>> dist(k + 2, vector<int>(N, INF));
        dist[0][src] = 0;

        int res = INF;
        for(int steps = 1; steps <= k + 1; ++steps){
            for(int prevNode = 0; prevNode < N; ++prevNode){
                for(const pair<int, int>& P: G[prevNode]){
                    int node = P.first;
                    int cost = P.second;
                    dist[steps][node] = min(dist[steps][node],
                                            dist[steps - 1][prevNode] + cost);
                }
            }
            res = min(res, dist[steps][dest]);
        }

        if(res == INF){
            res = -1;
        }

        return res;
    }
};