class Solution {
public:
    bool validPath(int N, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

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
};