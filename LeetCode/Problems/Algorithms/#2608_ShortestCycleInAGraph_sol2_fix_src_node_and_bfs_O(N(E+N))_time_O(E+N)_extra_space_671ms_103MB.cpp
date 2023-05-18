class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;

    int bfs(int srcNode, vector<int>& dist, const Graph& G){
        fill(dist.begin(), dist.end(), INF);

        queue<pair<int, int>> q;
        q.push({-1, srcNode});
        dist[srcNode] = 0;

        int minCycleLength = INF;
        while(!q.empty()){
            int parent = q.front().first;
            int node = q.front().second;
            q.pop();

            for(int nextNode: G[node]){
                if(dist[node] + 1 < dist[nextNode]){
                    dist[nextNode] = dist[node] + 1;
                    q.push({node, nextNode});
                }else if(nextNode != parent){
                    minCycleLength = min(minCycleLength, dist[node] + dist[nextNode] + 1);
                }
            }
        }

        return minCycleLength;
    }

public:
    int findShortestCycle(int N, vector<vector<int>>& edges) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int res = INF;
        vector<int> dist(N);
        for(int node = 0; node < N; ++node){
            int cycleLength = bfs(node, dist, G);
            res = min(res, cycleLength);
        }

        if(res == INF){
            res = -1;
        }

        return res;
    }
};