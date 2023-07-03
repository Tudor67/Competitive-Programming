class Solution {
public:
    double maxProbability(int N, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        const int E = edges.size();

        vector<vector<pair<double, int>>> G(N);
        for(int i = 0; i < E; ++i){
            int a = edges[i][0];
            int b = edges[i][1];
            G[a].push_back({succProb[i], b});
            G[b].push_back({succProb[i], a});
        }

        set<pair<double, int>> statesSet;
        vector<double> p(N);
        p[start] = 1;
        statesSet.insert({p[start], start});

        while(!statesSet.empty()){
            int node = prev(statesSet.end())->second;
            statesSet.erase(prev(statesSet.end()));

            for(const pair<double, int>& P: G[node]){
                double edgeProb = P.first;
                int nextNode = P.second;
                double nextProb = p[node] * edgeProb;
                if(nextProb > p[nextNode]){
                    statesSet.erase({p[nextNode], nextNode});
                    p[nextNode] = nextProb;
                    statesSet.insert({p[nextNode], nextNode});
                }
            }
        }

        return p[end];
    }
};