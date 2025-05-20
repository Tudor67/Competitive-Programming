class Solution {
public:
    vector<int> minimumTime(int N, vector<vector<int>>& edges, vector<int>& disappear) {
        const int E = edges.size();
        const int INF = 1e9;

        vector<vector<pair<int, int>>> G(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            int w = edge[2];
            G[a].push_back({b, w});
            G[b].push_back({a, w});
        }
        
        vector<int> minTime(N, INF);
        set<pair<int, int>> statesSet;
        minTime[0] = 0;
        statesSet.insert({minTime[0], 0});

        while(!statesSet.empty()){
            int node = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());

            for(auto& [nextNode, w]: G[node]){
                if(minTime[node] + w < min(minTime[nextNode], disappear[nextNode])){
                    statesSet.erase({minTime[nextNode], nextNode});
                    minTime[nextNode] = minTime[node] + w;
                    statesSet.insert({minTime[nextNode], nextNode});
                }
            }
        }

        for(int node = 0; node < N; ++node){
            if(minTime[node] == INF){
                minTime[node] = -1;
            }
        }

        return minTime;
    }
};