class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int E = edges.size();
        const int N = E;

        // Step 1: create graph G
        vector<vector<int>> G(N + 1);
        vector<int> degree(N + 1);
        for(int i = 0; i < E; ++i){
            int a = edges[i][0];
            int b = edges[i][1];
            G[a].push_back(b);
            G[b].push_back(a);
            degree[a] += 1;
            degree[b] += 1;
        }

        // Step 2: use topological sort idea to remove all paths pointing to the unique cycle of graph G
        queue<int> q;
        for(int node = 1; node <= N; ++node){
            if(degree[node] == 1){
                q.push(node);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                degree[nextNode] -= 1;
                if(degree[nextNode] == 1){
                    q.push(nextNode);
                }
            }
        }
        
        // Step 3: compute the max edge index of the cycle
        for(int i = E - 1; i >= 0; --i){
            if(degree[edges[i][0]] == 2 && degree[edges[i][1]] == 2){
                return edges[i];
            }
        }

        return {};
    }
};