class Solution {
private:
    int removeStones(int node, vector<bool>& vis, const vector<vector<int>>& G){
        if(vis[node]){
            return 0;
        }

        int removedStones = 1;
        vis[node] = true;
        for(int nextNode: G[node]){
            removedStones += removeStones(nextNode, vis, G);
        }

        return removedStones;
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        const int N = stones.size();

        vector<vector<int>> G(N);
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }

        int maxRemovedStones = 0;
        vector<bool> vis(N, false);
        for(int i = 0; i < N; ++i){
            if(!vis[i]){
                maxRemovedStones += removeStones(i, vis, G) - 1;
            }
        }

        return maxRemovedStones;
    }
};