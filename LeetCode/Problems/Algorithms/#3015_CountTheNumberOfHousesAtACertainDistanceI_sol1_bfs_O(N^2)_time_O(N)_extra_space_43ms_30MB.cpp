class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;
    
    void bfs(int srcNode, const Graph& G, vector<int>& dist){
        fill(dist.begin(), dist.end(), INF);
        queue<int> q;
        dist[srcNode] = 0;
        q.push(srcNode);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                if(dist[node] + 1 < dist[nextNode]){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }
    }
    
public:
    vector<int> countOfPairs(int n, int x, int y) {
        Graph G(n + 1);
        G[x].push_back(y);
        G[y].push_back(x);

        for(int i = 1; i + 1 <= n; ++i){
            G[i].push_back(i + 1);
            G[i + 1].push_back(i);
        }
        
        vector<int> res(n);
        vector<int> dist(n + 1);
        for(int srcNode = 1; srcNode <= n; ++srcNode){
            bfs(srcNode, G, dist);
            for(int node = 1; node <= n; ++node){
                if(dist[node] >= 1){
                    res[dist[node] - 1] += 1;
                }
            }
        }
        
        return res;
    }
};