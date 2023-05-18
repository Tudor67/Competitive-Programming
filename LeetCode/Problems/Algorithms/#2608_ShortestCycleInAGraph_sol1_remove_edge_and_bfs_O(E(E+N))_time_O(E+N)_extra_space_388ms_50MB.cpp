class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;

    int bfs(int srcNode, int destNode, const pair<int, int>& REMOVED_EDGE, vector<int>& dist, const Graph& G){
        fill(dist.begin(), dist.end(), INF);

        queue<int> q;
        q.push(srcNode);
        dist[srcNode] = 0;

        while(!q.empty() && dist[destNode] == INF){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                if(dist[node] + 1 < dist[nextNode]){
                    pair<int, int> edge = {node, nextNode};
                    pair<int, int> edgeRev = {nextNode, node};
                    if(edge != REMOVED_EDGE && edgeRev != REMOVED_EDGE){
                        dist[nextNode] = dist[node] + 1;
                        q.push(nextNode);
                    }
                }
            }
        }

        return dist[destNode] + 1;
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
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int cycleLength = bfs(a, b, {a, b}, dist, G);
            res = min(res, cycleLength);
        }

        if(res == INF){
            res = -1;
        }

        return res;
    }
};