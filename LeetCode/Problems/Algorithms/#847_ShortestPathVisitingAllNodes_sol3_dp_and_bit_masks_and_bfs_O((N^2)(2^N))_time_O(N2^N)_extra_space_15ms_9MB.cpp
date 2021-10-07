class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if((int)graph.size() <= 1){
            return 0;
        }
        
        const int N = graph.size();
        const int FULL_MASK = (1 << N) - 1;
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(N, vector<bool>(FULL_MASK + 1, false));
        for(int node = 0; node < N; ++node){
            q.push({node, 1 << node});
            vis[node][1 << node] = true;
        }
        
        int shortestPathLength = 0;
        while(true){
            for(int step = q.size(); step >= 1; --step){
                int node = q.front().first;
                int visMask = q.front().second;
                q.pop();
                
                if(visMask == FULL_MASK){
                    return shortestPathLength;
                }
                
                for(int nextNode: graph[node]){
                    int nextVisMask = visMask | (1 << nextNode);
                    if(!vis[nextNode][nextVisMask]){
                        q.push({nextNode, nextVisMask});
                        vis[nextNode][nextVisMask] = true;
                    }
                }
            }
            shortestPathLength += 1;
        }
        
        return -1;
    }
};