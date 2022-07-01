class Solution {
public:
    double maxProbability(int N, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        const int E = edges.size();
        
        vector<vector<pair<double, int>>> G(N);
        for(int i = 0; i < E; ++i){
            int x = edges[i][0];
            int y = edges[i][1];
            G[x].emplace_back(succProb[i], y);
            G[y].emplace_back(succProb[i], x);
        }
        
        set<pair<double, int>> states;
        vector<double> p(N);
        p[start] = 1;
        states.emplace(p[start], start);
        
        while(!states.empty()){
            int node = prev(states.end())->second;
            states.erase(prev(states.end()));
            
            if(node == end){
                break;
            }
            
            for(const pair<double, int>& P: G[node]){
                double edgeSuccProb = P.first;
                int nextNode = P.second;
                
                if(p[node] * edgeSuccProb > p[nextNode]){
                    states.erase({p[nextNode], nextNode});
                    p[nextNode] = p[node] * edgeSuccProb;
                    states.emplace(p[nextNode], nextNode);
                }
            }
        }
        
        return p[end];
    }
};