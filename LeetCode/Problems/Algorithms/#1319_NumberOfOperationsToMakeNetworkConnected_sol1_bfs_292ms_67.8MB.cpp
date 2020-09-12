class Solution {
private:
    void bfs(int node, const vector<vector<int>>& G, vector<bool>& vis){
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int next_node: G[node]){
                if(!vis[next_node]){
                    q.push(next_node);
                    vis[next_node] = true;
                }
            }
        }
    }
    
public:
    int makeConnected(int N, vector<vector<int>>& connections) {
        int min_connections = 0;
        
        if(connections.size() + 1 < N){
            min_connections = -1;
        }else{        
            vector<vector<int>> g(N);
            for(const vector<int>& EDGE: connections){
                g[EDGE[0]].push_back(EDGE[1]);
                g[EDGE[1]].push_back(EDGE[0]);
            }

            int connected_components = 0;
            vector<bool> vis(N, false);
            for(int node = 0; node < N; ++node){
                if(!vis[node]){
                    bfs(node, g, vis);
                    connected_components += 1;
                }
            }

            min_connections = connected_components - 1;
        }
        
        return min_connections;
    }
};