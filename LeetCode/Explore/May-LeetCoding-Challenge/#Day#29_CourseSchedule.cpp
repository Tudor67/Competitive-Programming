class Solution {
private:
    void dfs(const int& node, vector<vector<int>>& graph, vector<bool>& in_stack, bool& is_ok){
        in_stack[node] = true;
        while(!graph[node].empty() && is_ok){
            int next_node = graph[node].back();
            if(!in_stack[next_node]){
                graph[node].pop_back();
                dfs(next_node, graph, in_stack, is_ok);
            }else{
                is_ok = false;
            }
        }
        in_stack[node] = false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int N = numCourses;
        vector<vector<int>> graph(N);
        for(const vector<int>& arc: prerequisites){
            graph[arc[1]].push_back(arc[0]);
        }
        
        bool is_ok = true;
        vector<bool> in_stack(N, false);
        for(int node = 0; node < N; ++node){
            dfs(node, graph, in_stack, is_ok);
        }
        
        return is_ok;
    }
};