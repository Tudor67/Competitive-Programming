class Solution {
    void topological_sort(const vector<vector<int>>& g, vector<int>& answer){
        const int N = g.size();
        
        vector<int> out_degree(N);
        for(int node = 0; node < N; ++node){
            out_degree[node] = g[node].size();
        }
        
        vector<vector<int>> g_transpose(N);
        for(int node = 0; node < N; ++node){
            for(int next_node: g[node]){
                g_transpose[next_node].push_back(node);
            }
        }
        
        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(out_degree[node] == 0){
                q.push(node);
            }
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            answer.push_back(node);
            
            for(int prev_node: g_transpose[node]){
                --out_degree[prev_node];
                if(out_degree[prev_node] == 0){
                    q.push(prev_node);
                }
            }
        }
        
        if(answer.size() == N){
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