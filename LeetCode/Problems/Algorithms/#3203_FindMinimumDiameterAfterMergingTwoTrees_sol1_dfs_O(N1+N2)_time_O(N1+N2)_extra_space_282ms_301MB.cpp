class Solution {
private:
    using Graph = vector<vector<int>>;

    void computeDistances(int srcNode, const Graph& G, vector<int>& dist){
        const int N = G.size();
        const int INF = 1e9;

        dist.assign(N, INF);
        dist[srcNode] = 0;

        queue<int> q;
        q.push(srcNode);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                if(dist[nextNode] == INF){
                    dist[nextNode] = 1 + dist[node];
                    q.push(nextNode);
                }
            }
        }
    }

    int computeDiameter(vector<vector<int>>& edges){
        const int E = edges.size();
        const int N = E + 1;

        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> dist;
        computeDistances(0, G, dist);

        int farthestNode = max_element(dist.begin(), dist.end()) - dist.begin();
        computeDistances(farthestNode, G, dist);

        return *max_element(dist.begin(), dist.end());
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int diameter1 = computeDiameter(edges1);
        int diameter2 = computeDiameter(edges2);
        return max({diameter1,
                    diameter2,
                    (diameter1 - diameter1 / 2) + 1 + (diameter2 - diameter2 / 2)});
    }
};