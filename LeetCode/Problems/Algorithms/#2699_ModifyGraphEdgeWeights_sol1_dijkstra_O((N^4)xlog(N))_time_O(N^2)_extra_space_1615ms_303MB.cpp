class Solution {
private:
    using Graph = vector<vector<int>>;
    const int MAX_WEIGHT_OF_SPECIAL_EDGE = 2e9;
    const long long INF = 1e15;
    
    long long dijkstra(int src, int dest, const Graph& G){
        const int N = G.size();

        set<pair<long long, int>> statesSet;
        vector<long long> dist(N, INF);
        dist[src] = 0;
        statesSet.insert({dist[src], src});
        
        while(!statesSet.empty()){
            int node = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());

            if(node == dest){
                break;
            }
            
            for(int nextNode = 0; nextNode < N; ++nextNode){
                if(G[node][nextNode] >= 1){
                    if(dist[node] + G[node][nextNode] < dist[nextNode]){
                        statesSet.erase({dist[nextNode], nextNode});
                        dist[nextNode] = dist[node] + G[node][nextNode];
                        statesSet.insert({dist[nextNode], nextNode});
                    }
                }
            }
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