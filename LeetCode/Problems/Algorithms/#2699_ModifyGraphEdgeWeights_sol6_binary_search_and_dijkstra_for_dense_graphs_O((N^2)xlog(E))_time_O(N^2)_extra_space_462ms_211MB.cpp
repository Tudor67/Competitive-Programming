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

            if(bestNode == -1){
                break;
            }

            for(int nextNode = 0; nextNode < N; ++nextNode){
                dist[nextNode] = min(dist[nextNode], dist[bestNode] + weight[bestNode][nextNode]);
            }

            processed[bestNode] = true;
        }

        return dist[destination];
    }

    void setWeightsOfSpecialEdges(vector<vector<int>>& weight, vector<pair<int, int>>& specialEdges,
                                  const int MAX_SPECIAL_EDGES){
        for(int i = 0; i < (int)specialEdges.size(); ++i){
            int a = specialEdges[i].first;
            int b = specialEdges[i].second;
            if(i < MAX_SPECIAL_EDGES){
                weight[a][b] = 1;
                weight[b][a] = 1;
            }else{
                weight[a][b] = INF;
                weight[b][a] = INF;
            }
        }
    }

    vector<vector<int>> extractEdges(vector<vector<int>>& edges, vector<vector<int>>& weight){
        const int E = edges.size();
        vector<vector<int>> res(E);
        for(int i = 0; i < E; ++i){
            int a = edges[i][0];
            int b = edges[i][1];
            res[i] = {a, b, weight[a][b]};
        }
        return res;
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
                w = INF;
                specialEdges.push_back({a, b});
            }
            weight[a][b] = w;
            weight[b][a] = w;
        }

        if(dijkstra(source, destination, weight) < target){
            return {};
        }

        if(dijkstra(source, destination, weight) == target){
            return extractEdges(edges, weight);
        }

        if(specialEdges.empty()){
            return {};
        }

        int l = 1;
        int r = (int)specialEdges.size();
        while(l != r){
            int mid = (l + r) / 2;
            setWeightsOfSpecialEdges(weight, specialEdges, mid);
            if(dijkstra(source, destination, weight) <= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        const int MAX_SPECIAL_EDGES = r;
        setWeightsOfSpecialEdges(weight, specialEdges, MAX_SPECIAL_EDGES);
        int shortestDist = dijkstra(source, destination, weight);
        if(shortestDist <= target){
            int diff = target - shortestDist;
            int a = specialEdges[MAX_SPECIAL_EDGES - 1].first;
            int b = specialEdges[MAX_SPECIAL_EDGES - 1].second;
            weight[a][b] += diff;
            weight[b][a] += diff;
            return extractEdges(edges, weight);
        }

        return {};
    }
};