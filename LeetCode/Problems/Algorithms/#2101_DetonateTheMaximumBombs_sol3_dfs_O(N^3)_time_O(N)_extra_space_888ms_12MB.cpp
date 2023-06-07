class Solution {
private:
    long long computeSquareDistance(const vector<int>& A, const vector<int>& B){
        long long dx = A[0] - B[0];
        long long dy = A[1] - B[1];
        return dx * dx + dy * dy;
    }

    void dfs(int node, vector<bool>& vis, vector<vector<int>>& bombs){
        const int N = bombs.size();
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(int nextNode = 0; nextNode < N; ++nextNode){
            long long ri = bombs[node][2];
            if(computeSquareDistance(bombs[node], bombs[nextNode]) <= ri * ri){
                dfs(nextNode, vis, bombs);
            }
        }
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        const int N = bombs.size();

        int res = 0;
        vector<bool> vis(N);
        for(int node = 0; node < N; ++node){
            fill(vis.begin(), vis.end(), false);
            dfs(node, vis, bombs);

            int visNodesCount = count(vis.begin(), vis.end(), true);
            res = max(res, visNodesCount);
        }

        return res;
    }
};