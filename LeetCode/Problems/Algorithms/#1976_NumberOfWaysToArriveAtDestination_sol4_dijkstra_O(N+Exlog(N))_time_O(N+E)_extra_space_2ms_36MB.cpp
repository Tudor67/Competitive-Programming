class Solution {
public:
    int countPaths(int N, vector<vector<int>>& roads) {
        const int E = roads.size();
        const long long INF = 1e18;
        const int MODULO = 1'000'000'007;

        vector<vector<pair<int, int>>> G(N);
        for(vector<int>& road: roads){
            int a = road[0];
            int b = road[1];
            int t = road[2];
            G[a].push_back({b, t});
            G[b].push_back({a, t});
        }

        vector<long long> minTime(N, INF);
        vector<int> count(N);
        set<pair<long long, int>> statesSet;

        minTime[0] = 0;
        count[0] = 1;
        statesSet.insert({minTime[0], 0});

        while(!statesSet.empty()){
            int node = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());

            for(auto& [nextNode, t]: G[node]){
                if(minTime[node] + t < minTime[nextNode]){
                    statesSet.erase({minTime[nextNode], nextNode});
                    minTime[nextNode] = minTime[node] + t;
                    count[nextNode] = count[node];
                    statesSet.insert({minTime[nextNode], nextNode});
                }else if(minTime[node] + t == minTime[nextNode]){
                    count[nextNode] = (count[nextNode] + count[node]) % MODULO;
                }
            }
        }

        return count[N - 1];
    }
};