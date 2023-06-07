class Solution {
private:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& isConnected){
        const int N = isConnected.size();
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(int nextNode = 0; nextNode < N; ++nextNode){
            if(isConnected[node][nextNode]){
                dfs(nextNode, vis, isConnected);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int N = isConnected.size();

        int provinces = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                provinces += 1;
                dfs(node, vis, isConnected);
            }
        }

        return provinces;
    }
};