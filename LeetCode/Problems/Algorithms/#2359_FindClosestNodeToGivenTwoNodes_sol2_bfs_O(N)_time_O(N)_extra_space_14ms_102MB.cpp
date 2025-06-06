class Solution {
private:
    vector<int> computeDistances(vector<int>& nextNodeFrom, int srcNode){
        const int N = nextNodeFrom.size();
        vector<int> dist(N, -1);
        dist[srcNode] = 0;
        for(int node = srcNode; nextNodeFrom[node] != -1 && dist[nextNodeFrom[node]] == -1; node = nextNodeFrom[node]){
            dist[nextNodeFrom[node]] = dist[node] + 1;
        }
        return dist;
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1 = computeDistances(edges, node1);
        vector<int> dist2 = computeDistances(edges, node2);

        const int N = edges.size();
        int bestDist = INT_MAX;
        int bestDistNode = -1;
        for(int node = 0; node < N; ++node){
            if(dist1[node] >= 0 && dist2[node] >= 0){
                int dist = max(dist1[node], dist2[node]);
                if(bestDist > dist){
                    bestDist = dist;
                    bestDistNode = node;
                }
            }
        }

        return bestDistNode;
    }
};