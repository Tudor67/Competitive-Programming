class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> g(n);
        for(const vector<int>& arc: flights){
            g[arc[0]].push_back({arc[1], arc[2]});
        }
        
        // d[dst][cnt] - distance from src to dst using cnt nodes
        vector<vector<int>> d(n, vector<int>(K + 1, -1));
        d[src][0] = 0;
        
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;
        pq.push({d[src][0], 0, src});
        
        while(!pq.empty()){
            int dist, cnt, node;
            tie(dist, cnt, node) = pq.top();
            pq.pop();
            
            for(const pair<int, int>& p: g[node]){
                int next_node = p.first;
                int next_node_cost = p.second;
                int next_node_cnt = cnt + (next_node != dst);
                if(next_node_cnt <= K){
                    if(d[next_node][next_node_cnt] == -1 ||
                       d[next_node][next_node_cnt] > d[node][cnt] + next_node_cost){
                        d[next_node][next_node_cnt] = d[node][cnt] + next_node_cost;
                        pq.push({d[next_node][next_node_cnt], next_node_cnt, next_node});
                    }
                }
            }
        }
        
        int answer = -1;
        for(int cnt = 0; cnt <= K; ++cnt){
            if(d[dst][cnt] != -1){
                if(answer == -1 || d[dst][cnt] < answer){
                    answer = d[dst][cnt];
                }
            }
        }
        
        return answer;
    }
};