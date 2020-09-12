class Solution {
private:
    void bfs(int src, const vector<vector<int>>& A, vector<bool>& vis){
        queue<int> q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int next_node = 0; next_node < A[node].size(); ++next_node){
                if(!vis[next_node] && A[node][next_node]){
                    q.push(next_node);
                    vis[next_node] = true;
                }
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& A) {
        const int N = A.size();
        int connected_components = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                bfs(node, A, vis);
                connected_components += 1;
            }
        }
        return connected_components;
    }
};