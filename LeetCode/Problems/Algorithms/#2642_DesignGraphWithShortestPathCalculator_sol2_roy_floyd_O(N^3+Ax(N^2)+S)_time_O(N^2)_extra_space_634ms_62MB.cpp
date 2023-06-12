class Graph {
private:
    const int INF = 1e9;
    const int N;
    vector<vector<int>> dist;

public:
    Graph(int n, vector<vector<int>>& edges): N(n) {
        dist.resize(N, vector<int>(N, INF));
        for(int i = 0; i < N; ++i){
            dist[i][i] = 0;
        }

        for(const vector<int>& EDGE: edges){
            dist[EDGE[0]][EDGE[1]] = EDGE[2];
        }

        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                dist[i][j] = min(dist[i][j], dist[i][edge[0]] + edge[2] + dist[edge[1]][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        if(dist[node1][node2] == INF){
            return -1;
        }
        return dist[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */