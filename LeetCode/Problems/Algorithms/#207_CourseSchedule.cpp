class Solution {
private:
    void dfs(int node, const vector<vector<int>>& next_nodes,
             vector<bool>& vis, vector<bool>& is_in_stack, bool& can_finish){
        vis[node] = true;
        is_in_stack[node] = true;
        for(int next_node: next_nodes[node]){
            if(is_in_stack[next_node]){
                can_finish = false;
            }
            if(!vis[next_node]){
                dfs(next_node, next_nodes, vis, is_in_stack, can_finish);
            }
        }
        is_in_stack[node] = false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> next_nodes(numCourses);
        for(const vector<int>& v: prerequisites){
            next_nodes[v[0]].push_back(v[1]);
        }
        
        vector<bool> vis(numCourses, false);
        vector<bool> is_in_stack(numCourses, false);
        bool can_finish = true;
        for(int node = 0; node < numCourses; ++node){
            dfs(node, next_nodes, vis, is_in_stack, can_finish);
        }
        
        return can_finish;
    }
};