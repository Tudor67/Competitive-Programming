class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
        rank.resize(N + 1, 0);
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
        int x_root = find(x);
        int y_root = find(y);
        if(x_root != y_root){
            if(rank[x_root] <= rank[y_root]){
                parent[x_root] = y_root;
            }else{
                parent[y_root] = x_root;
            }
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
};

class Solution {
private:
    vector<string> grid;
    int N;
    
    void join_cell_components(int row, int col, DSU& dsu){
        char cell = grid[row][col];
        vector<vector<int>> components_indices;
        
        int cell_start_idx = 4 * (N * row + col);
        if(cell == ' ')  components_indices = {{cell_start_idx + 0, cell_start_idx + 1, cell_start_idx + 2, cell_start_idx + 3}};
        if(cell == '\\') components_indices = {{cell_start_idx + 0, cell_start_idx + 1}, {cell_start_idx + 2, cell_start_idx + 3}};
        if(cell == '/')  components_indices = {{cell_start_idx + 3, cell_start_idx + 0}, {cell_start_idx + 1, cell_start_idx + 2}};
        
        for(int i = 0; i < components_indices.size(); ++i){
            for(int j = 1; j < components_indices[i].size(); ++j){
                dsu.join(components_indices[i][0], components_indices[i][j]);
            }
        }
    }
    
    void join_horizontal_consecutive_components(int row, int col1, int col2, DSU& dsu){
        assert(col1 + 1 == col2);
        
        char cell1 = grid[row][col1];
        char cell2 = grid[row][col2];
        
        int cell1_start_idx = 4 * (N * row + col1);
        int component1_idx = cell1_start_idx + (cell1 == ' ' ? 0 : 1);
        
        int cell2_start_idx = 4 * (N * row + col2);
        int component2_idx = cell2_start_idx + (cell2 == ' ' ? 0 : 3);
        
        dsu.join(component1_idx, component2_idx);
    }
    
    void join_vertical_consecutive_components(int row1, int row2, int col, DSU& dsu){
        assert(row1 + 1 == row2);
        
        char cell1 = grid[row1][col];
        char cell2 = grid[row2][col];
        
        int cell1_start_idx = 4 * (N * row1 + col);
        int component1_idx = cell1_start_idx + (cell1 == ' ' ? 0 : 2);
        
        int cell2_start_idx = 4 * (N * row2 + col);
        int component2_idx = cell2_start_idx;
        
        dsu.join(component1_idx, component2_idx); 
    }
    
public:
    int regionsBySlashes(vector<string>& grid) {
        this->grid = grid;
        this->N = grid.size();
        
        DSU dsu(4 * N * N);
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                join_cell_components(row, col, dsu);
                if(col + 1 < N){
                    join_horizontal_consecutive_components(row, col, col + 1, dsu);
                }
                if(row + 1 < N){
                    join_vertical_consecutive_components(row, row + 1, col, dsu);
                }
            }
        }
        
        int regions_cnt = 0;
        vector<bool> vis(4 * N * N, false);
        for(int cell = 0; cell < 4 * N * N; ++cell){
            int cell_root = dsu.find(cell);
            if(!vis[cell_root]){
                regions_cnt += 1;
            }
            vis[cell_root] = true;
        }
        
        return regions_cnt;
    }
};