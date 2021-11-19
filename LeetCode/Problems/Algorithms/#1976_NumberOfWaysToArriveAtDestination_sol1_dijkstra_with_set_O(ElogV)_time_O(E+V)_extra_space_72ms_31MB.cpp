class Solution {
public:
    int countPaths(int N, vector<vector<int>>& roads) {
        const long long INF = LLONG_MAX / 10;
        const int MODULO = 1e9 + 7;
        
        vector<vector<pair<int, int>>> g(N);
        for(const vector<int>& ROAD: roads){
            int x = ROAD[0];
            int y = ROAD[1];
            int t = ROAD[2];
            g[x].emplace_back(y, t);
            g[y].emplace_back(x, t);
        }
        
        vector<long long> minTime(N, INF);
        vector<int> count(N, 0);
        using State = pair<long long, int>;
        set<State> stateSet;
        stateSet.emplace(0, 0);
        minTime[0] = 0;
        count[0] = 1;
        
        while(!stateSet.empty()){
            int x = stateSet.begin()->second;
            stateSet.erase(stateSet.begin());
            
            for(const pair<int, int>& P: g[x]){
                int y = P.first;
                int t = P.second;
                if(minTime[x] + t < minTime[y]){
                    stateSet.erase({minTime[y], y});
                    minTime[y] = minTime[x] + t;
                    count[y] = count[x];
                    stateSet.emplace(minTime[y], y);
                }else if(minTime[x] + t == minTime[y]){
                    count[y] += count[x];
                    count[y] %= MODULO;
                }
            }
        }
        
        return count[N - 1];
    }
};