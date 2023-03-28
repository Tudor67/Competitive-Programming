class Solution {
private:
    using Graph = vector<vector<int>>;

    void bfs(int srcNode, vector<bool>& vis, const Graph& G){
        queue<int> q;
        if(!vis[srcNode]){
            q.push(srcNode);
            vis[srcNode] = true;
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                if(!vis[nextNode]){
                    q.push(nextNode);
                    vis[nextNode] = true;
                }
            }
        }
    }

public:
    int makeConnected(int N, vector<vector<int>>& connections) {
        const int E = connections.size();

        if(N - 1 > E){
            return -1;
        }

        Graph G(N);
        for(const vector<int>& CONNECTION: connections){
            int a = CONNECTION[0];
            int b = CONNECTION[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int connectedComponents = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                connectedComponents += 1;
                bfs(node, vis, G);
            }
        }
        
        return connectedComponents - 1;
    }
};