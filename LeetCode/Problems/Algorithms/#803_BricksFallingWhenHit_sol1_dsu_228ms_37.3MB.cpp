class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    vector<bool> top_connection_status;
    
public:
    DSU(const int& N){
        top_connection_status.resize(N + 1, false);
        size.resize(N + 1, 1);
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
                size[y_root] += size[x_root];
                top_connection_status[y_root] = top_connection_status[y_root] || top_connection_status[x_root];
            }else{
                parent[y_root] = x_root;
                size[x_root] += size[y_root];
                top_connection_status[x_root] = top_connection_status[x_root] || top_connection_status[y_root];
            }
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
    
    int get_size(int x){
        int x_root = find(x);
        return size[x_root];
    }
    
    void set_top_connection(int x, bool flag = true){
        int x_root = find(x);
        top_connection_status[x_root] = flag;
    }
    
    bool has_top_connection(int x){
        int x_root = find(x);
        return top_connection_status[x_root];
    }
};

class Solution {
private:
    int N;
    int M;
    
    int get_idx(const int& ROW, const int& COL){
        return (M * ROW + COL);
    }
    
    bool is_inside(const int& ROW, const int& COL){
        return (0 <= ROW && ROW < N && 0 <= COL && COL < M);
    }
    
public:
    vector<int> hitBricks(vector<vector<int>>& original_grid, vector<vector<int>>& hits) {
        this->N = original_grid.size();
        this->M = original_grid[0].size();
        
        // original_grid will not be changed
        // we will change only its copy: grid
        vector<vector<int>> grid = original_grid;
        
        // unmark cells which are hit
        for(const vector<int>& HIT: hits){
            grid[HIT[0]][HIT[1]] = 0;
        }
        
        const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        const int MAX_IDX = get_idx(N - 1, M - 1);
        DSU dsu(MAX_IDX);
        
        // group cells (with grid[row][col] == 1) in cc (connected components)
        // mark ccs which contain cells (with grid[0][col] == 1) to have top_connection_status = true
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < M; ++col){
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int neigh_row = row + DIRECTION.first;
                    int neigh_col = col + DIRECTION.second;
                    if(is_inside(neigh_row, neigh_col) && grid[row][col] * grid[neigh_row][neigh_col] == 1){
                        int idx = get_idx(row, col);
                        int neigh_idx = get_idx(neigh_row, neigh_col);
                        dsu.join(idx, neigh_idx);
                    }
                }
                if(row == 0 && grid[row][col] == 1){
                    dsu.set_top_connection(get_idx(0, col), true);
                }
            }
        }
        
        // move from the last hit to the first and compute the number of cell that should drop at each step
        vector<int> answer(hits.size(), 0);
        for(int i = (int)hits.size() - 1; i >= 0; --i){
            int row = hits[i][0];
            int col = hits[i][1];
            int idx = get_idx(row, col);
            
            if(original_grid[row][col] == 1){
                // prepare to update answer[i]
                // it will be possible only if there exists at least one cc with top connection
                //                             or the current cell is in the first row
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int neigh_row = row + DIRECTION.first;
                    int neigh_col = col + DIRECTION.second;
                    int neigh_idx = get_idx(neigh_row, neigh_col);
                    if(is_inside(neigh_row, neigh_col) && grid[neigh_row][neigh_col] == 1){
                        if(dsu.find(idx) != dsu.find(neigh_idx)){
                            if(!dsu.has_top_connection(neigh_idx)){
                                answer[i] += dsu.get_size(neigh_idx);
                            }
                            dsu.join(idx, neigh_idx);
                        }
                    }
                }
                
                if(row == 0){
                    dsu.set_top_connection(idx, true);
                }
                
                // set answer[i] = 0 if the current cc does not have a top connection
                if(!dsu.has_top_connection(idx)){
                    answer[i] = 0;
                }
                
                grid[row][col] = 1;
            }
        }
        
        return answer;
    }
};