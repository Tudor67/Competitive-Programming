class Solution {
private:
    const int INF = 1e8;
    
    void dfs(int prevNode, int node, int level, vector<int>& minLevelOf, const vector<vector<int>>& G, vector<vector<int>>& answer){
        minLevelOf[node] = level;
        for(int nextNode: G[node]){
            if(minLevelOf[nextNode] == INF){
                dfs(node, nextNode, level + 1, minLevelOf, G, answer);
            }
            if(nextNode != prevNode){
                minLevelOf[node] = min(minLevelOf[nextNode], minLevelOf[node]);
            }
        }
        if(level <= minLevelOf[node] && prevNode != -1){
            answer.push_back({prevNode, node});
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int N, vector<vector<int>>& connections) {
        vector<vector<int>> g(N);
        for(const vector<int>& EDGE: connections){
            g[EDGE[0]].push_back(EDGE[1]);
            g[EDGE[1]].push_back(EDGE[0]);
        }
        
        vector<int> minLevelOf(N, INF);
        vector<vector<int>> answer;
        dfs(-1, 0, 0, minLevelOf, g, answer);
        
        return answer;
    }
};