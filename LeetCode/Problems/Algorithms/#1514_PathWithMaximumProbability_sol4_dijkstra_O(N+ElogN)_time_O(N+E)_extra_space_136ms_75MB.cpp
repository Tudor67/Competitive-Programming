class Solution {
public:
    double maxProbability(int N, vector<vector<int>>& edges, vector<double>& succProb, int startNode, int endNode) {
        const int E = edges.size();

        vector<vector<pair<double, int>>> G(N);
        for(int i = 0; i < E; ++i){
            int a = edges[i][0];
            int b = edges[i][1];
            G[a].push_back({succProb[i], b});
            G[b].push_back({succProb[i], a});
        }

        vector<double> maxProb(N);
        set<pair<double, int>> statesSet;
        maxProb[startNode] = 1;
        statesSet.insert({maxProb[startNode], startNode});

        while(!statesSet.empty()){
            int node = prev(statesSet.end())->second;
            statesSet.erase(prev(statesSet.end()));

            for(const pair<double, int>& P: G[node]){
                double p = P.first;
                int nextNode = P.second;
                if(maxProb[node] * p > maxProb[nextNode]){
                    statesSet.erase({maxProb[nextNode], nextNode});
                    maxProb[nextNode] = maxProb[node] * p;
                    statesSet.insert({maxProb[nextNode], nextNode});
                }
            }
        }

        return maxProb[endNode];
    }
};