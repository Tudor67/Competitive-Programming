class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;
    
    void dfs(int prevNode, int node, int level, vector<int>& minLevelOf, const Graph& G, vector<vector<int>>& res){
        if(minLevelOf[node] != INF){
            return;
        }
        minLevelOf[node] = level;
        for(int nextNode: G[node]){
            if(nextNode != prevNode){
                dfs(node, nextNode, level + 1, minLevelOf, G, res);
                minLevelOf[node] = min(minLevelOf[node], minLevelOf[nextNode]);
            }
        }
        if(minLevelOf[node] == level && prevNode != INF){
            res.push_back({prevNode, node});
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int N, vector<vector<int>>& connections) {
        Graph G(N);
        for(const vector<int>& EDGE: connections){
            int x = EDGE[0];
            int y = EDGE[1];
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        vector<int> minLevelOf(N, INF);
        vector<vector<int>> res;
        dfs(INF, 0, 0, minLevelOf, G, res);
        
        return res;
    }
};