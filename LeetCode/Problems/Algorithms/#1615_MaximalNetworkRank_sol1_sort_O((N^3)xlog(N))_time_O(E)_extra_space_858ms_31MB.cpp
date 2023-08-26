class Solution {
public:
    int maximalNetworkRank(int N, vector<vector<int>>& roads) {
        const int E = roads.size();

        vector<vector<int>> G(N);
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int res = 0;
        vector<pair<int, int>> edges;
        for(int a = 0; a < N; ++a){
            for(int b = a + 1; b < N; ++b){
                edges.clear();

                for(int node: {a, b}){
                    for(int nextNode: G[node]){
                        edges.push_back({min(node, nextNode), max(node, nextNode)});
                    }
                }

                sort(edges.begin(), edges.end());
                edges.resize(unique(edges.begin(), edges.end()) - edges.begin());

                res = max(res, (int)edges.size());
            }
        }

        return res;
    }
};