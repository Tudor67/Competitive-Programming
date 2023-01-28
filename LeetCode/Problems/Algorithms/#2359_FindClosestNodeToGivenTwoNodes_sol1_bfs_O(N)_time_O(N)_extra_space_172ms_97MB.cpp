class Solution {
private:
    const int INF = 1e9;

    void computeDistances(int node, vector<int>& edges, vector<int>& dist){
        fill(dist.begin(), dist.end(), INF);
        dist[node] = 0;
        while(edges[node] != -1 && dist[edges[node]] == INF){
            dist[edges[node]] = dist[node] + 1;
            node = edges[node];
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int N = edges.size();

        vector<int> dist1(N);
        vector<int> dist2(N);
        computeDistances(node1, edges, dist1);
        computeDistances(node2, edges, dist2);

        int resNode = -1;
        int resDist = INF;
        for(int node = 0; node < N; ++node){
            int maxDist = max(dist1[node], dist2[node]);
            if(maxDist < resDist){
                resDist = maxDist;
                resNode = node;
            }
        }

        return resNode;
    }
};