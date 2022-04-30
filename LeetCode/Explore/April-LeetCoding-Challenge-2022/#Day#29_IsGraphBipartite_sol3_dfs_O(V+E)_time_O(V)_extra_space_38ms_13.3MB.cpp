class Solution {
private:
    void dfs(int node, vector<int>& colorOf, vector<vector<int>>& graph, bool& isBipartite){
        for(int nextNode: graph[node]){
            if(colorOf[nextNode] == -1){
                colorOf[nextNode] = (colorOf[node] + 1) % 2;
                dfs(nextNode, colorOf, graph, isBipartite);
            }else if(colorOf[nextNode] == colorOf[node]){
                isBipartite = false;
            }
        }
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int N = graph.size();
        
        vector<int> colorOf(N, -1);
        bool isBipartite = true;
        for(int node = 0; node < N && isBipartite; ++node){
            if(colorOf[node] == -1){
                colorOf[node] = 0;
                dfs(node, colorOf, graph, isBipartite);
            }
        }
        
        return isBipartite;
    }
};