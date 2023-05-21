class Solution {
private:
    void dfs(int node, vector<int>& color, bool& isValid, vector<vector<int>>& graph){
        for(int nextNode: graph[node]){
            if(color[nextNode] == -1){
                color[nextNode] = 1 - color[node];
                dfs(nextNode, color, isValid, graph);
            }else if(color[nextNode] != 1 - color[node]){
                isValid = false;
            }
        }
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int N = graph.size();

        bool isValid = true;
        vector<int> color(N, -1);
        for(int node = 0; node < N && isValid; ++node){
            if(color[node] == -1){
                color[node] = 0;
                dfs(node, color, isValid, graph);
            }
        }

        return isValid;
    }
};