class Graph {
private:
    const int INF = 1e9;
    const int N;
    vector<vector<int>> edgeCost;
    vector<int> dist;
    vector<bool> processed;

public:
    Graph(int n, vector<vector<int>>& edges): N(n) {
        dist.resize(N);
        processed.resize(N);

        edgeCost.assign(N, vector<int>(N, INF));
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            edgeCost[a][b] = w;
        }

        for(int node = 0; node < N; ++node){
            edgeCost[node][node] = 0;
        }
    }
    
    void addEdge(vector<int> edge) {
        int a = edge[0];
        int b = edge[1];
        int w = edge[2];
        edgeCost[a][b] = w;
    }
    
    int shortestPath(int node1, int node2) {
        fill(processed.begin(), processed.end(), false);
        fill(dist.begin(), dist.end(), INF);
        dist[node1] = 0;

        for(int iteration = 1; iteration <= N - 1; ++iteration){
            int minDist = INF;
            int minDistNode = INF;
            for(int node = 0; node < N; ++node){
                if(!processed[node] && dist[node] < minDist){
                    minDist = dist[node];
                    minDistNode = node;
                }
            }

            if(minDist == INF || minDistNode == node2){
                break;
            }

            for(int nextNode = 0; nextNode < N; ++nextNode){
                dist[nextNode] = min(dist[nextNode], dist[minDistNode] + edgeCost[minDistNode][nextNode]);
            }

            processed[minDistNode] = true;
        }

        if(dist[node2] == INF){
            return -1;
        }
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */