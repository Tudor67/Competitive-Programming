class Solution {
private:
    using Graph = vector<vector<int>>;
    
    void dfs(int parentNode, int node, const Graph& G, int seats, vector<int>& subtreeSize, long long& res){
        subtreeSize[node] = 1;
        for(int nextNode: G[node]){
            if(nextNode != parentNode){
                dfs(node, nextNode, G, seats, subtreeSize, res);
                subtreeSize[node] += subtreeSize[nextNode];
            }
        }
        if(node != 0){
            res += (subtreeSize[node] + seats - 1) / seats;
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
        
        long long res = 0;
        vector<int> subtreeSize(N);
        dfs(-1, 0, G, seats, subtreeSize, res);
        
        return res;
    }
};