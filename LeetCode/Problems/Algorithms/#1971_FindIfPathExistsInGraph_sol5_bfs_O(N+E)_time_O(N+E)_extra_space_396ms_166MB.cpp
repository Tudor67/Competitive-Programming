class Solution {
private:
    using Graph = vector<vector<int>>;

    bool bfs(int source, int destination, const Graph& G){
        const int N = G.size();
        
        vector<bool> vis(N, false);
        queue<int> q;
        q.push(source);
        vis[source] = true;

        while(!q.empty() && !vis[destination]){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                if(!vis[nextNode]){
                    vis[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }

        return vis[destination];
    }

public:
    bool validPath(int N, vector<vector<int>>& edges, int source, int destination) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        return bfs(source, destination, G);
    }
};