class Solution {
public:
    int countPaths(int N, vector<vector<int>>& roads) {
        const long long MODULO = 1'000'000'007;
        const long long INF = 1e18;

        vector<vector<long long>> minTime(N, vector<long long>(N, INF));
        vector<vector<long long>> count(N, vector<long long>(N, 1));
        for(vector<int>& road: roads){
            int a = road[0];
            int b = road[1];
            int t = road[2];
            minTime[a][b] = t;
            minTime[b][a] = t;
        }
        
        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    if(minTime[i][k] + minTime[k][j] < minTime[i][j]){
                        minTime[i][j] = minTime[i][k] + minTime[k][j];
                        count[i][j] = (count[i][k] * count[k][j]) % MODULO;
                    }else if(minTime[i][k] + minTime[k][j] == minTime[i][j]){
                        count[i][j] = (count[i][j] + count[i][k] * count[k][j]) % MODULO;
                    }
                }
            }
        }

        return count[0][N - 1];
    }
};