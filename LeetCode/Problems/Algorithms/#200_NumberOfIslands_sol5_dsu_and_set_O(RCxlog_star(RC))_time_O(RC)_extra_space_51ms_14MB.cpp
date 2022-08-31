class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const int& N){
        rank.resize(N + 1);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
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
private:
    int getIdx(int row, int col, const int& COLS){
        return row * COLS + col;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        DSU dsu(getIdx(ROWS - 1, COLS - 1, COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == '1'){
                    if(row + 1 < ROWS && grid[row + 1][col] == '1'){
                        dsu.join(getIdx(row, col, COLS), getIdx(row + 1, col, COLS));
                    }
                    if(col + 1 < COLS && grid[row][col + 1] == '1'){
                        dsu.join(getIdx(row, col, COLS), getIdx(row, col + 1, COLS));
                    }
                }
            }
        }
        
        unordered_set<int> islandIds;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == '1'){
                    islandIds.insert(dsu.find(getIdx(row, col, COLS)));
                }
            }
        }
        
        return islandIds.size();
    }
};