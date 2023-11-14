class Graph {
private:
    const int INF = 1e9;
    const int N;
    vector<vector<int>> minCost;

public:
    Graph(int n, vector<vector<int>>& edges): N(n) {
        minCost.assign(N, vector<int>(N, INF));
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            minCost[a][b] = w;
        }

        for(int i = 0; i < N; ++i){
            minCost[i][i] = 0;
        }

        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int a = edge[0];
        int b = edge[1];
        int w = edge[2];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                minCost[i][j] = min(minCost[i][j], minCost[i][a] + w + minCost[b][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        if(minCost[node1][node2] == INF){
            return -1;
        }
        return minCost[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */