class Solution {
private:
    using Graph = vector<vector<int>>;
    
    bool isValid(const int& N, const Graph& G, const vector<int>& REDUNDANT_EDGE){
        vector<bool> vis(N + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                if(!vis[nextNode]){
                    const vector<int> EDGE = {min(node, nextNode), max(node, nextNode)};
                    if(EDGE != REDUNDANT_EDGE){
                        q.push(nextNode);
                        vis[nextNode] = true;
                    }
                }
            }
        }
        
        return (count(vis.begin(), vis.end(), true) == N);
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int N = edges.size();
        
        Graph g(N + 1);
        for(int i = 0; i < N; ++i){
            int x = edges[i][0];
            int y = edges[i][1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        vector<int> redundantEdge;
        for(int i = N - 1; i >= 0 && redundantEdge.empty(); --i){
            if(isValid(N, g, edges[i])){
                redundantEdge = edges[i];
            }
        }
        
        return redundantEdge;
    }
};