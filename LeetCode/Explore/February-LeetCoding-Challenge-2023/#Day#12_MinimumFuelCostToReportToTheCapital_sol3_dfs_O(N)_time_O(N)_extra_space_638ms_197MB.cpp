class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int parentNode, int node, const Graph& G, vector<int>& subtreeSize){
        subtreeSize[node] = 1;
        for(int childNode: G[node]){
            if(childNode != parentNode){
                dfs(node, childNode, G, subtreeSize);
                subtreeSize[node] += subtreeSize[childNode];
            }
        }
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        const int N = roads.size() + 1;

        Graph G(N);
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> subtreeSize(N);
        dfs(-1, 0, G, subtreeSize);

        long long res = 0;
        for(int node = 1; node < N; ++node){
            res += (subtreeSize[node] + seats - 1) / seats;
        }

        return res;
    }
};