class Solution {
private:
    void back(int node, vector<bool>& vis, const vector<vector<int>>& GRAPH,
              vector<int>& path, vector<vector<int>>& paths){
        if(node == (int)GRAPH.size() - 1){
            paths.push_back(path);
        }else{
            for(int next_node: GRAPH[node]){
                if(!vis[next_node]){
                    vis[next_node] = true;
                    path.push_back(next_node);
                    back(next_node, vis, GRAPH, path, paths);
                    vis[next_node] = false;
                    path.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        vector<bool> vis(graph.size(), false);
        vis[0] = true;
        path.push_back(0);
        back(0, vis, graph, path, paths);
        return paths;
    }
};