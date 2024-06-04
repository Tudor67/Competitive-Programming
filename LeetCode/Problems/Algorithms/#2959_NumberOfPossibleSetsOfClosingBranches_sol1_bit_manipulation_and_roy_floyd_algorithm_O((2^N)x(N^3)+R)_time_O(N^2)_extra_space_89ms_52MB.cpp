class Solution {
private:
    bool isPossible(vector<vector<int>> dist, int maxDistanceThreshold, int mask){
        const int N = dist.size();

        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    int kBit = (mask >> k) & 1;
                    int iBit = (mask >> i) & 1;
                    int jBit = (mask >> j) & 1;
                    if(kBit == 1 && iBit == 1 && jBit == 1){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                int iBit = (mask >> i) & 1;
                int jBit = (mask >> j) & 1;
                if(iBit == 1 && jBit == 1 && dist[i][j] > maxDistanceThreshold){
                    return false;
                }
            }
        }

        return true;
    }

public:
    int numberOfSets(int N, int maxDistance, vector<vector<int>>& roads) {
        const int INF = 1e9;
        const int FULL_MASK = (1 << N) - 1;

        vector<vector<int>> dist(N, vector<int>(N, INF));
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            int w = ROAD[2];
            dist[a][b] = min(dist[a][b], w);
            dist[b][a] = min(dist[b][a], w);
        }

        for(int i = 0; i < N; ++i){
            dist[i][i] = 0;
        }
        
        int goodSets = 0;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            if(isPossible(dist, maxDistance, mask)){
                goodSets += 1;
            }
        }

        return goodSets;
    }
};