class Solution {
private:
    void back(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths){
        if(node == (int)graph.size() - 1){
            paths.push_back(path);
        }else{
            for(int nextNode: graph[node]){
                path.push_back(nextNode);
                back(nextNode, graph, path, paths);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        vector<vector<int>> paths;
        back(0, graph, path, paths);
        return paths;
    }
};