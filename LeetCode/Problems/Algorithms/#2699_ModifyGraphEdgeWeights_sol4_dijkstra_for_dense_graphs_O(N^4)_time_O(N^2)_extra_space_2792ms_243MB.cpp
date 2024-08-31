class Solution {
private:
    const int INF = 1e9 + 17;

    int dijkstra(int source, int destination, vector<vector<int>>& weight){
        const int N = weight.size();

        vector<int> dist(N, INF);
        vector<bool> processed(N, false);
        dist[source] = 0;

        for(int step = 1; step <= N && !processed[destination]; ++step){
            int bestNode = -1;
            for(int node = 0; node < N; ++node){
                if(!processed[node] && dist[node] != INF){
                    if(bestNode == -1 || dist[bestNode] > dist[node]){
                        bestNode = node;
                    }
                }
            }

            for(int nextNode = 0; nextNode < N; ++nextNode){
                dist[nextNode] = min(dist[nextNode], dist[bestNode] + weight[bestNode][nextNode]);
            }

            processed[bestNode] = true;
        }

        return dist[destination];
    }

public:
    vector<vector<int>> modifiedGraphEdges(int N, vector<vector<int>>& edges, int source, int destination, int target) {
        const int E = edges.size();

        vector<vector<int>> weight(N, vector<int>(N, INF));
        vector<pair<int, int>> specialEdges;
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            if(w == -1){
                w = 1;
                specialEdges.push_back({a, b});
            }
            weight[a][b] = w;
            weight[b][a] = w;
        }

        int shortestDist = dijkstra(source, destination, weight);
        for(int i = 0; i < (int)specialEdges.size() && shortestDist < target; ++i){
            int a = specialEdges[i].first;
            int b = specialEdges[i].second;
            int diff = target - shortestDist;
            weight[a][b] += diff;
            weight[b][a] += diff;
            shortestDist = dijkstra(source, destination, weight);
        }

        if(shortestDist == target){
            vector<vector<int>> res(E);
            for(int i = 0; i < E; ++i){
                int a = edges[i][0];
                int b = edges[i][1];
                res[i] = {a, b, weight[a][b]};
            }
            return res;
        }

        return {};
    }
};