class Solution {
private:
    void dfs(vector<vector<int>>& g, 
             int node, vector<bool>& is_in_stack, vector<bool>& is_in_answer,
             vector<int>& answer, bool& is_valid){
        is_in_stack[node] = true;
        
        while(is_valid && !g[node].empty()){
            int next_node = g[node].back();
            g[node].pop_back();
            if(is_in_stack[next_node]){
                is_valid = false;
            }else{
                dfs(g, next_node, is_in_stack, is_in_answer, answer, is_valid);
            }
        }
        
        is_in_stack[node] = false;
        if(!is_in_answer[node]){
            is_in_answer[node] = true;
            answer.push_back(node);
        }
    }
    
    void topological_sort(vector<vector<int>>& g, vector<int>& answer){
        const int N = g.size();
        
        bool is_valid = true;
        vector<bool> is_in_stack(N, false);
        vector<bool> is_in_answer(N, false);
        for(int node = 0; is_valid && node < N; ++node){
            if(!is_in_answer[node]){
                dfs(g, node, is_in_stack, is_in_answer, answer, is_valid);
            }
        }
        
        if(is_valid){
            reverse(answer.begin(), answer.end());
        }else{
            answer.clear();
        }
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(const vector<int>& v: prerequisites){
            g[v[1]].push_back(v[0]);
        }
        
        vector<int> answer;
        topological_sort(g, answer);
        
        return answer;
    }
};