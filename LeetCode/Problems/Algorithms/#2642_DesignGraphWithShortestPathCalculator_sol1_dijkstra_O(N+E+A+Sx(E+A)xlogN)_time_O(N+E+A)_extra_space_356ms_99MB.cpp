class Graph {
private:
    const int INF = 1e9;
    const int N;
    vector<vector<pair<int, int>>> G;
    
public:
    Graph(int n, vector<vector<int>>& edges): N(n) {
        G.resize(N);
        for(const vector<int>& EDGE: edges){
            addEdge(EDGE);
        }
    }
    
    void addEdge(vector<int> edge) {
        int node = edge[0];
        int nextNode = edge[1];
        int cost = edge[2];
        G[node].push_back({cost, nextNode});
    }
    
    int shortestPath(int node1, int node2) {
        set<pair<int, int>> statesSet;
        vector<int> dist(N, INF);
        
        dist[node1] = 0;
        statesSet.insert({dist[node1], node1});
        
        while(!statesSet.empty()){
            int node = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());
            
            if(node == node2){
                return dist[node2];
            }
            
            for(const pair<int, int>& P: G[node]){
                int cost = P.first;
                int nextNode = P.second;
                
                if(dist[node] + cost < dist[nextNode]){
                    statesSet.erase({dist[nextNode], nextNode});
                    dist[nextNode] = dist[node] + cost;
                    statesSet.insert({dist[nextNode], nextNode});
                }
            }
        }
        
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */