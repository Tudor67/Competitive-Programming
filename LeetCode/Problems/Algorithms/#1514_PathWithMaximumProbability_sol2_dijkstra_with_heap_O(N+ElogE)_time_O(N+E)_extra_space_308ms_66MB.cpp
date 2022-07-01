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
        
        priority_queue<pair<double, int>> maxHeap;
        vector<double> p(N);
        p[start] = 1;
        maxHeap.emplace(p[start], start);
        
        while(!maxHeap.empty()){
            double heapProbNode = maxHeap.top().first;
            int node = maxHeap.top().second;
            maxHeap.pop();
            
            if(heapProbNode < p[node]){
                continue;
            }
            
            if(node == end){
                break;
            }
            
            for(const pair<double, int>& P: G[node]){
                double edgeSuccProb = P.first;
                int nextNode = P.second;
                
                if(p[node] * edgeSuccProb > p[nextNode]){
                    p[nextNode] = p[node] * edgeSuccProb;
                    maxHeap.emplace(p[nextNode], nextNode);
                }
            }
        }
        
        return p[end];
    }
};