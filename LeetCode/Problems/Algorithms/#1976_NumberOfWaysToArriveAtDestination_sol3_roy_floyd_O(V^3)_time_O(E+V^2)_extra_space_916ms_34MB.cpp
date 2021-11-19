class Solution {
private:
    const long long INF = LLONG_MAX / 10;
    const int MODULO = 1e9 + 7;
    
    int computeCount(int y, vector<vector<pair<int, int>>>& g, vector<vector<long long>>& minTime, vector<long long>& count){
        const int N = g.size();
        if(y == 0){
            count[y] = 1;
        }else if(count[y] == INF){
            count[y] = 0;
            for(const pair<int, int>& P: g[y]){
                int x = P.first;
                int t = P.second;
                if(minTime[0][x] + t == minTime[0][y]){
                    count[y] += computeCount(x, g, minTime, count);
                    count[y] %= MODULO;
                }
            }
        }
        return count[y];
    }
    
public:
    int countPaths(int N, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(N);
        vector<vector<long long>> minTime(N, vector<long long>(N, INF));
        for(const vector<int>& ROAD: roads){
            int x = ROAD[0];
            int y = ROAD[1];
            int t = ROAD[2];
            g[x].emplace_back(y, t);
            g[y].emplace_back(x, t);
            minTime[x][y] = t;
            minTime[y][x] = t;
        }
        
        for(int x = 0; x < N; ++x){
            minTime[x][x] = 0;
        }
        
        for(int k = 0; k < N; ++k){
            for(int x = 0; x < N; ++x){
                for(int y = 0; y < N; ++y){
                    minTime[x][y] = min(minTime[x][y], minTime[x][k] + minTime[k][y]);
                }
            }
        }
        
        vector<long long> count(N, INF);
        computeCount(N - 1, g, minTime, count);
        
        return count[N - 1];
    }
};