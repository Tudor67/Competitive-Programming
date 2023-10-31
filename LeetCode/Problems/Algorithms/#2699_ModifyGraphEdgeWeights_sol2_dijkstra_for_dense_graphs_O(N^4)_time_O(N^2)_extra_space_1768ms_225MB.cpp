class Solution {
private:
    using Graph = vector<vector<int>>;
    const int MAX_WEIGHT_OF_SPECIAL_EDGE = 2e9;
    const long long INF = 1e15;
    
    long long dijkstra(int src, int dest, const Graph& G){
        const int N = G.size();

        vector<long long> dist(N, INF);
        vector<bool> processed(N, false);
        dist[src] = 0;
        
        for(int iteration = 1; iteration <= N - 1 && !processed[dest]; ++iteration){
            long long minDist = INF;
            int minDistNode = 0;
            for(int node = 0; node < N; ++node){
                if(!processed[node] && dist[node] < minDist){
                    minDist = dist[node];
                    minDistNode = node;
                }
            }

            for(int nextNode = 0; nextNode < N; ++nextNode){
                if(G[minDistNode][nextNode] >= 1){
                    dist[nextNode] = min(dist[nextNode], dist[minDistNode] + G[minDistNode][nextNode]);
                }
            }

            processed[minDistNode] = true;
        }
        
        return dist[dest];
    }
    
public:
    vector<vector<int>> modifiedGraphEdges(int N, vector<vector<int>>& edges, int src, int dest, int target) {
        Graph G(N, vector<int>(N, 0));
        vector<pair<int, int>> specialEdges;
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            
            if(w == -1){
                specialEdges.push_back({a, b});
                w = MAX_WEIGHT_OF_SPECIAL_EDGE;
                w = MAX_WEIGHT_OF_SPECIAL_EDGE;
            }
            
            G[a][b] = w;
            G[b][a] = w;
        }

        long long initialCost = dijkstra(src, dest, G);
        if(initialCost > target){
            for(const pair<int, int>& SPECIAL_EDGE: specialEdges){
                int a = SPECIAL_EDGE.first;
                int b = SPECIAL_EDGE.second;
                G[a][b] = 1;
                G[b][a] = 1;
                
                long long cost = dijkstra(src, dest, G);
                if(cost <= target){
                    long long x = target - cost;
                    G[a][b] += x;
                    G[b][a] += x;
                    break;
                }
            }
        }
        
        long long finalCost = dijkstra(src, dest, G);
        vector<vector<int>> resEdges;
        if(finalCost == target){
            for(int a = 0; a < N; ++a){
                for(int b = a + 1; b < N; ++b){
                    if(G[a][b] >= 1){
                        resEdges.push_back({a, b, G[a][b]});
                    }
                }
            }
        }
        
        return resEdges;
    }
};