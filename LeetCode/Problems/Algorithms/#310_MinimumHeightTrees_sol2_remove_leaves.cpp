class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        vector<int> degree(n, 0);
        for(const vector<int>& edge: edges){
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
            ++degree[edge[0]];
            ++degree[edge[1]];
        }
        
        queue<int> q;
        vector<int> step(n, -1);
        for(int node = 0; node < n; ++node){
            if(degree[node] <= 1){
                q.push(node);
                step[node] = 0;
            }
        }
        
        // At each step: remove all the current leaves
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(int y: neighbors[x]){
                --degree[y];
                if(degree[y] == 1){
                    q.push(y);
                    step[y] = 1 + step[x];
                }
            }
        }
        
        vector<int> answer;
        int last_step = *max_element(step.begin(), step.end());
        // Answer: nodes removed at the last step
        for(int node = 0; node < n; ++node){
            if(step[node] == last_step){
                answer.push_back(node);
            }
        }
        
        return answer;
    }
};