class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int E = edges.size();
        const int N = E;

        // Step 1: create graph G
        vector<vector<pair<int, int>>> G(N + 1);
        vector<int> degree(N + 1);
        for(int edgeIndex = 0; edgeIndex < E; ++edgeIndex){
            int a = edges[edgeIndex][0];
            int b = edges[edgeIndex][1];
            G[a].push_back({b, edgeIndex});
            G[b].push_back({a, edgeIndex});
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

        vector<bool> vis(E + 1, false);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(const pair<int, int>& P: G[node]){
                int nextNode = P.first;
                int edgeIndex = P.second;
                vis[edgeIndex] = true;
                degree[nextNode] -= 1;
                if(degree[nextNode] == 1){
                    q.push(nextNode);
                }
            }
        }

        // Step 3: run bfs on the cycle and compute the max edge index of the cycle
        int indexOfRedundantEdge = -1;
        int startNode = max_element(degree.begin(), degree.end()) - degree.begin();
        q.push(startNode);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(const pair<int, int>& P: G[node]){
                int nextNode = P.first;
                int edgeIndex = P.second;
                if(!vis[edgeIndex]){
                    indexOfRedundantEdge = max(indexOfRedundantEdge, edgeIndex);
                    vis[edgeIndex] = true;
                    q.push(nextNode);
                }
            }
        }

        return edges[indexOfRedundantEdge];
    }
};