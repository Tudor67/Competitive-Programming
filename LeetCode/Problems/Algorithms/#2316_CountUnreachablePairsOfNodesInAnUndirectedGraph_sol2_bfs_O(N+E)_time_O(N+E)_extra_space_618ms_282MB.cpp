class Solution {
private:
    int bfs(int srcNode, vector<bool>& vis, const vector<vector<int>>& G){
        queue<int> q;
        q.push(srcNode);
        vis[srcNode] = true;
        
        int ccSize = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ccSize += 1;
            
            for(int nextNode: G[node]){
                if(!vis[nextNode]){
                    q.push(nextNode);
                    vis[nextNode] = true;
                }
            }
        }
        
        return ccSize;
    }
    
public:
    long long countPairs(int N, vector<vector<int>>& edges) {
        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        long long pairs = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                int ccSize = bfs(node, vis, G);
                pairs += ccSize * 1LL * (N - ccSize);
            }
        }
        
        return pairs / 2;
    }
};