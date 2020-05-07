class Solution {
private:
    void dfs(int node, const vector<vector<int>>& next_nodes,
             vector<bool>& is_in_stack, vector<bool>& vis, bool& is_valid,
             vector<int>& answer){
        is_in_stack[node] = true;
        vis[node] = true;
        for(int next_node: next_nodes[node]){
            if(is_in_stack[next_node]){
                is_valid = false;
            }
            else if(!vis[next_node] && is_valid){
                dfs(next_node, next_nodes, is_in_stack, vis, is_valid, answer);
            }
        }
        is_in_stack[node] = false;
        answer.push_back(node);
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build the graph
        vector<vector<int>> next_nodes(numCourses);
        for(const vector<int>& v: prerequisites){
            next_nodes[v[1]].push_back(v[0]);
        }
        
        // topological sort
        vector<bool> vis(numCourses, false);
        vector<bool> is_in_stack(numCourses, false);
        bool is_valid = true;
        vector<int> answer;
        for(int node = 0; node < numCourses; ++node){
            if(!vis[node]){
                dfs(node, next_nodes, is_in_stack, vis, is_valid, answer);
            }
        }
        reverse(answer.begin(), answer.end());
        
        // check if the answer is valid (i.e., doesn't contain cycles)
        if(!is_valid){
            answer.clear();
        }
        
        return answer;
    }
};