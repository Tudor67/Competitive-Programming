class Solution {
private:
    using Graph = vector<vector<int>>;

    int computeShortestDistance(int src, int dest, const Graph& G){
        const int N = G.size();
        const int INF = 1e9;

        queue<int> q;
        vector<int> dist(N, INF);
        q.push(src);
        dist[src] = 0;

        while(!q.empty() && dist[dest] == INF){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                if(dist[nextNode] > dist[node] + 1){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }

        return dist[dest];
    }

public:
    vector<int> shortestDistanceAfterQueries(int N, vector<vector<int>>& queries) {
        const int Q = queries.size();

        Graph G(N);
        for(int node = 0; node + 1 < N;++node){
            G[node].push_back(node + 1);
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];
            G[a].push_back(b);
            res[i] = computeShortestDistance(0, N - 1, G);
        }

        return res;
    }
};