class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int parent, int node, const Graph& G, vector<int>& values, int k, vector<int>& subtreeSum){
        subtreeSum[node] = values[node] % k;
        for(int nextNode: G[node]){
            if(nextNode != parent){
                dfs(node, nextNode, G, values, k, subtreeSum);
                subtreeSum[node] = (subtreeSum[node] + subtreeSum[nextNode]) % k;
            }
        }
    }

public:
    int maxKDivisibleComponents(int N, vector<vector<int>>& edges, vector<int>& values, int k) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> subtreeSum(N);
        dfs(-1, 0, G, values, k, subtreeSum);

        return count(subtreeSum.begin(), subtreeSum.end(), 0);
    }
};