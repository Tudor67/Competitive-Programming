class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> g(n);
        for(const vector<int>& arc: flights){
            g[arc[0]].push_back({arc[1], arc[2]});
        }
        
        const int INF = 1e9;
        vector<int> vis(n, false);
        vector<int> distance(n, INF);
        distance[src] = 0;
        queue<int> q;
        q.push(src);
        
        for(int i = 0; i <= K; ++i){
            queue<pair<int, int>> improvements;
            
            for(int cnt = q.size(); cnt > 0; --cnt){
                int node = q.front();
                q.pop();
                
                for(const pair<int, int>& p: g[node]){
                    int next_node = p.first;
                    int cost = p.second;
                    if(distance[node] + cost < distance[next_node]){
                        improvements.push({next_node, distance[node] + cost});
                        if(!vis[next_node]){
                            vis[next_node] = true;
                            q.push(next_node);
                        }
                    }
                }
            }
            
            while(!improvements.empty()){
                int node = improvements.front().first;
                int min_distance = min(distance[node], improvements.front().second);
                distance[node] = min_distance;
                vis[node] = false;
                improvements.pop();
            }
        }
        
        int answer = distance[dst];
        if(answer == INF){
            answer = -1;
        }
        
        return answer;
    }
};