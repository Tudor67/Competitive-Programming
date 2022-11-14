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
        // Coordinate compression
        vector<int> rows;
        vector<int> cols;
        for(const vector<int>& STONE: stones){
            int row = STONE[0];
            int col = STONE[1];
            rows.push_back(row);
            cols.push_back(col);
        }
        
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        rows.resize(unique(rows.begin(), rows.end()) - rows.begin());
        cols.resize(unique(cols.begin(), cols.end()) - cols.begin());
        
        // DSU on compressed coordinates
        DSU dsu(rows.size() + cols.size());
        for(const vector<int>& STONE: stones){
            int row = STONE[0];
            int col = STONE[1];
            int compressedRow = lower_bound(rows.begin(), rows.end(), row) - rows.begin();
            int compressedCol = lower_bound(cols.begin(), cols.end(), col) - cols.begin();
            dsu.join(compressedRow, rows.size() + compressedCol);
        }
        
        vector<bool> vis(rows.size() + cols.size(), false);
        for(const vector<int>& STONE: stones){
            int row = STONE[0];
            int compressedRow = lower_bound(rows.begin(), rows.end(), row) - rows.begin();
            vis[dsu.find(compressedRow)] = true;
        }
        
        int totalStones = stones.size();
        int connectedComponents = count(vis.begin(), vis.end(), true);
        
        return totalStones - connectedComponents;
    }
};