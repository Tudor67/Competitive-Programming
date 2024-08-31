class Solution {
private:
    void dfs(int node, vector<bool>& vis, const vector<vector<int>>& G){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(int nextNode: G[node]){
            dfs(nextNode, vis, G);
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        const int N = stones.size();

        vector<vector<int>> G(N);
        unordered_map<int, int> prevNodeAtRow;
        unordered_map<int, int> prevNodeAtCol;
        
        for(int i = 0; i < N; ++i){
            int row = stones[i][0];
            int col = stones[i][1];

            if(prevNodeAtRow.count(row)){
                int j = prevNodeAtRow[row];
                G[i].push_back(j);
                G[j].push_back(i);
            }
            if(prevNodeAtCol.count(col)){
                int j = prevNodeAtCol[col];
                G[i].push_back(j);
                G[j].push_back(i);
            }

            prevNodeAtRow[row] = i;
            prevNodeAtCol[col] = i;
        }

        int maxRemovedStones = N;
        vector<bool> vis(N, false);
        for(int i = 0; i < N; ++i){
            if(!vis[i]){
                dfs(i, vis, G);
                maxRemovedStones -= 1;
            }
        }

        return maxRemovedStones;
    }
};