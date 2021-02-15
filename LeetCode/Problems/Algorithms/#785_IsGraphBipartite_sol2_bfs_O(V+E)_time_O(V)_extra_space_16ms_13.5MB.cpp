class Solution {
private:
    void bfs(const int& SRC_NODE, vector<int>& color, vector<vector<int>>& G, bool& isBipartiteGraph){
        queue<int> q;
        q.push(SRC_NODE);
        color[SRC_NODE] = 0;
        while(!q.empty() && isBipartiteGraph){
            int node = q.front();
            q.pop();
            for(int nextNode: G[node]){
                if(color[nextNode] == -1){
                    color[nextNode] = (1 + color[node]) % 2;
                    q.push(nextNode);
                }else if(color[nextNode] != (1 + color[node]) % 2){
                    isBipartiteGraph = false;
                }
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
                bfs(node, color, graph, isBipartiteGraph);
            }
        }
        return isBipartiteGraph;
    }
};