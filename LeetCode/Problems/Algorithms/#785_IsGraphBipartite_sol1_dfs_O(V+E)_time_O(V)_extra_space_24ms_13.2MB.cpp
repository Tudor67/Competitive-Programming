class Solution {
private:
    void dfs(int node, vector<int>& color, vector<vector<int>>& G, bool& isBipartiteGraph){
        for(int nextNode: G[node]){
            if(color[nextNode] == -1){
                color[nextNode] = (1 + color[node]) % 2;
                dfs(nextNode, color, G, isBipartiteGraph);
            }else if(color[nextNode] != (1 + color[node]) % 2){
                isBipartiteGraph = false;
            }
        }
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int N = graph.size();
        vector<int> color(N, -1);
        bool isBipartiteGraph = true;
        for(int node = 0; node < N; ++node){
            if(isBipartiteGraph && color[node] == -1){
                color[node] = 0;
                dfs(node, color, graph, isBipartiteGraph);
            }
        }
        return isBipartiteGraph;
    }
};