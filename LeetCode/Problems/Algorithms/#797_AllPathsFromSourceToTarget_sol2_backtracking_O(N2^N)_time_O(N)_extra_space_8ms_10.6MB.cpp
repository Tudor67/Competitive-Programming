class Solution {
private:
    void back(int node, int destNode, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths){
        if(node == destNode){
            paths.push_back(path);
        }else{
            for(int nextNode: graph[node]){
                path.push_back(nextNode);
                back(nextNode, destNode, graph, path, paths);
                path.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        const int N = graph.size();
        vector<int> path = {0};
        vector<vector<int>> paths;
        back(0, N - 1, graph, path, paths);
        return paths;
    }
};