class Solution {
public:
    int minCost(int N, vector<vector<int>>& edges) {
        const int E = edges.size();
        const int INF = 1e9;

        vector<vector<pair<int, int>>> G(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            int w = edge[2];
            G[a].push_back({w, b});
            G[b].push_back({2 * w, a});
        }

        vector<int> dist(N, INF);
        set<pair<int, int>> statesSet;
        dist[0] = 0;
        statesSet.insert({dist[0], 0});

        while(!statesSet.empty()){
            int node = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());

            if(node == N - 1){
                return dist[node];
            }

            for(const auto& [w, nextNode]: G[node]){
                if(dist[nextNode] > dist[node] + w){
                    statesSet.erase({dist[nextNode], nextNode});
                    dist[nextNode] = dist[node] + w;
                    statesSet.insert({dist[nextNode], nextNode});
                }
            }
        }

        return -1;
    }
};