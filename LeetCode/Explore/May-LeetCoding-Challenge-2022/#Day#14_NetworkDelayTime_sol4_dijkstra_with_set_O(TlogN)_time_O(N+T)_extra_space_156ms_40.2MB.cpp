class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
    const int INF = 1e9;
    
    void dijkstra(int startNode, const Graph& G, vector<int>& minDist){
        fill(minDist.begin(), minDist.end(), INF);
        minDist[startNode] = 0;
        
        set<pair<int, int>> stateSet;
        stateSet.emplace(minDist[startNode], startNode);
        while(!stateSet.empty()){
            int node = stateSet.begin()->second;
            stateSet.erase(stateSet.begin());
            
            for(const pair<int, int>& P: G[node]){
                int w = P.first;
                int nextNode = P.second;
                if(minDist[node] + w < minDist[nextNode]){
                    stateSet.erase({minDist[nextNode], nextNode});
                    minDist[nextNode] = minDist[node] + w;
                    stateSet.emplace(minDist[nextNode], nextNode);
                }
            }
        }
    }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        Graph G(N);
        for(const vector<int>& V: times){
            int x = V[0];
            int y = V[1];
            int w = V[2];
            G[x - 1].emplace_back(w, y - 1);
        }
        
        vector<int> minDist(N);
        dijkstra(K - 1, G, minDist);
        
        int res = *max_element(minDist.begin(), minDist.end());
        if(res == INF){
            res = -1;
        }
        
        return res;
    }
};