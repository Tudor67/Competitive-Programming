class Solution {
public:
    vector<int> findMinHeightTrees(int N, vector<vector<int>>& edges) {
        vector<vector<int>> g(N);
        vector<int> degree(N);
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0];
            int y = EDGE[1];
            g[x].push_back(y);
            g[y].push_back(x);
            degree[x] += 1;
            degree[y] += 1;
        }
        
        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(degree[node] <= 1){
                q.push(node);
            }
        }
        
        int nodes = N;
        while(nodes > 2){
            for(int i = q.size(); i >= 1; --i){
                int node = q.front();
                q.pop();
                
                nodes -= 1;
                
                for(int nextNode: g[node]){
                    degree[nextNode] -= 1;
                    if(degree[nextNode] == 1){
                        q.push(nextNode);
                    }
                }
            }
        }
        
        vector<int> answer;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            answer.push_back(node);
        }
        
        return answer;
    }
};