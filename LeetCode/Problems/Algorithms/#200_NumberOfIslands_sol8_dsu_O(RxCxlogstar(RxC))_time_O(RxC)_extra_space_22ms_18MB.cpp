class DSU{
private:
    vector<int> rank;
    vector<int> parent;

public:
    DSU(const int N){
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

    int join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
            return 1;
        }
        return 0;
    }
};

class Solution {
private:
    enum CellType { WATER = '0', LAND = '1' };

    int getIndex(int row, int col, const int COLS){
        return row * COLS + col;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int islands = 0;
        DSU dsu(ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == CellType::LAND){
                    islands += 1;
                    if(col + 1 < COLS && grid[row][col + 1] == CellType::LAND){
                        islands -= dsu.join(getIndex(row, col, COLS), getIndex(row, col + 1, COLS));
                    }
                    if(row + 1 < ROWS && grid[row + 1][col] == CellType::LAND){
                        islands -= dsu.join(getIndex(row, col, COLS), getIndex(row + 1, col, COLS));
                    }
                }
            }
        }

        return islands;
    }
};