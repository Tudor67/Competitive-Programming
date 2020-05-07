class Solution {
private:
    void dfs(int node, const vector<vector<int>>& next_nodes,
             vector<bool>& is_in_stack, vector<bool>& vis, bool& is_ok){
        vis[node] = true;
        is_in_stack[node] = true;
        
        for(int next_node: next_nodes[node]){
            if(is_in_stack[next_node]){
                is_ok = false;
            }
            if(is_ok && !vis[next_node]){
                dfs(next_node, next_nodes, is_in_stack, vis, is_ok);
            }
        }
        
        is_in_stack[node] = false;
    }
    
    bool is_valid(const int& numCourses,
                  const vector<vector<int>>& next_nodes){
        vector<bool> is_in_stack(numCourses, false);
        vector<bool> vis(numCourses, false);
        
        bool is_ok = true;
        for(int i = 0; is_ok && i < numCourses; ++i){
            if(!vis[i]){
                dfs(i, next_nodes, is_in_stack, vis, is_ok);
            }
        }
        
        return is_ok;
    }
    
    void topological_sort(const int& numCourses,
                          const vector<vector<int>>& next_nodes,
                          vector<int>& answer){
        vector<int> in_degree(numCourses, 0);
        for(int node = 0; node < numCourses; ++node){
            for(int next_node: next_nodes[node]){
                ++in_degree[next_node];
            }
        }
        
        queue<int> q;
        for(int node = 0; node < numCourses; ++node){
            if(in_degree[node] == 0){
                q.push(node);
            }
        }
        
        answer.resize(numCourses);
        int pos = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(in_degree[node] == 0){
                answer[pos++] = node;
            }
            
            for(int next_node: next_nodes[node]){
                --in_degree[next_node];
                if(in_degree[next_node] == 0){
                    q.push(next_node);
                }
            }
        }
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> next_nodes(numCourses);
        for(const vector<int>& v: prerequisites){
            next_nodes[v[1]].push_back(v[0]);
        }
        
        vector<int> answer;
        if(is_valid(numCourses, next_nodes)){
            topological_sort(numCourses, next_nodes, answer);
        }
        
        return answer;
    }
};