class Solution { 
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build the graph
        vector<vector<int>> next_nodes(numCourses);
        for(const vector<int>& v: prerequisites){
            next_nodes[v[1]].push_back(v[0]);
        }
        
        // topological sort
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
        
        vector<int> pos(numCourses, -1);
        int idx = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            pos[node] = idx;
            ++idx;
            
            for(int next_node: next_nodes[node]){
                --in_degree[next_node];
                if(in_degree[next_node] == 0){
                    q.push(next_node);
                }
            }
        }
        
        // check if the answer is valid
        bool is_valid = true;
        vector<int> answer(numCourses);
        for(int node = 0; is_valid && node < numCourses; ++node){
            if(pos[node] == -1){
                is_valid = false;
            }
            else{
                answer[pos[node]] = node;
            }
            
            for(int next_node: next_nodes[node]){
                if(pos[node] > pos[next_node]){
                    is_valid = false;
                    break;
                }
            }
        }
        
        if(!is_valid){
            answer.clear();
        }
        
        return answer;
    }
};