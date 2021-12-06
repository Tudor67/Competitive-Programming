class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        const int N = patience.size();
        const int INF = 1e8;
        
        vector<vector<int>> g(N);
        for(const vector<int>& EDGE: edges){
            g[EDGE[0]].push_back(EDGE[1]);
            g[EDGE[1]].push_back(EDGE[0]);
        }
        
        vector<int> dist(N, INF);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: g[node]){
                if(dist[node] + 1 < dist[nextNode]){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }
        
        int maxTime = 0;
        for(int node = 1; node < N; ++node){
            int messages = (2 * dist[node] + patience[node] - 1) / patience[node];
            int t = (messages - 1) * patience[node] + 2 * dist[node];
            maxTime = max(maxTime, t);
        }
        
        return maxTime + 1;
    }
};