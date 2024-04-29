class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int parent, int node, const Graph& G, vector<int>& subtreeSize, vector<int>& distancesSum){
        subtreeSize[node] = 1;
        for(int nextNode: G[node]){
            if(nextNode != parent){
                dfs(node, nextNode, G, subtreeSize, distancesSum);
                subtreeSize[node] += subtreeSize[nextNode];
                distancesSum[node] += distancesSum[nextNode];
                distancesSum[node] += subtreeSize[nextNode];
            }
        }
    }

    void rerooting(int parent, int node, const Graph& G, vector<int>& subtreeSize, vector<int>& distancesSum){
        if(parent >= 0){
            distancesSum[node] = distancesSum[parent] - subtreeSize[node] + (int)G.size() - subtreeSize[node];
        }
        for(int nextNode: G[node]){
            if(nextNode != parent){
                rerooting(node, nextNode, G, subtreeSize, distancesSum);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> subtreeSize(N);
        vector<int> distancesSum(N);
        dfs(-1, 0, G, subtreeSize, distancesSum);

        rerooting(-1, 0, G, subtreeSize, distancesSum);

        return distancesSum;
    }
};