class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
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
            
            for(const pair<int, int>& EDGE: G[node]){
                int w = EDGE.first;
                int nextNode = EDGE.second;
                if(dist[node] + w < dist[nextNode]){
                    statesSet.erase({dist[nextNode], nextNode});
                    dist[nextNode] = dist[node] + w;
                    statesSet.insert({dist[nextNode], nextNode});
                }
            }
        }
        
        return dist[dest];
    }
    
public:
    vector<vector<int>> modifiedGraphEdges(int N, vector<vector<int>>& edges, int src, int dest, int target) {
        Graph G(N);
        vector<pair<int, int>> specialEdges;
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            
            if(w == -1){
                specialEdges.push_back({a, b});
            }else{
                G[a].push_back({w, b});
                G[b].push_back({w, a});
            }
        }

        long long initialCost = dijkstra(src, dest, G);
        if(initialCost > target){
            while(!specialEdges.empty()){
                int a = specialEdges.back().first;
                int b = specialEdges.back().second;
                specialEdges.pop_back();

                G[a].push_back({1, b});
                G[b].push_back({1, a});
                
                long long cost = dijkstra(src, dest, G);
                if(cost <= target){
                    long long x = target - cost;
                    G[a].back().first += x;
                    G[b].back().first += x;
                    break;
                }
            }
        }
        
        long long finalCost = dijkstra(src, dest, G);
        vector<vector<int>> resEdges;
        if(finalCost == target){
            while(!specialEdges.empty()){
                int a = specialEdges.back().first;
                int b = specialEdges.back().second;
                specialEdges.pop_back();
                resEdges.push_back({a, b, MAX_WEIGHT_OF_SPECIAL_EDGE});
            }

            for(int a = 0; a < N; ++a){
                for(const pair<int, int>& EDGE: G[a]){
                    int w = EDGE.first;
                    int b = EDGE.second;
                    if(a < b){
                        resEdges.push_back({a, b, w});
                    }
                }
            }
        }
        
        return resEdges;
    }
};