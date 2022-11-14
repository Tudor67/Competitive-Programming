class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const int& N){
        rank.resize(N);
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for(const vector<int>& STONE: stones){
            int row = STONE[0];
            int col = STONE[1];
            maxRow = max(maxRow, row);
            maxCol = max(maxCol, col);
        }
        
        DSU dsu(maxRow + 1 + maxCol + 1);
        for(const vector<int>& STONE: stones){
            int row = STONE[0];
            int col = STONE[1];
            dsu.join(row, maxRow + 1 + col);
        }
        
        vector<bool> vis(maxRow + 1 + maxCol + 1, false);
        for(const vector<int>& STONE: stones){
            int row = STONE[0];
            int col = STONE[1];
            vis[dsu.find(row)] = true;
        }
        
        int totalStones = stones.size();
        int connectedComponents = count(vis.begin(), vis.end(), true);
        
        return totalStones - connectedComponents;
    }
};