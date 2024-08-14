class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(int row, int col, vector<vector<bool>>& vis){
        const int ROWS = vis.size();
        const int COLS = vis[0].size();
        if(!(0 <= row && row < ROWS && 0 <= col && col < COLS) || vis[row][col]){
            return;
        }
        vis[row][col] = true;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            dfs(row + DIRECTION.first, col + DIRECTION.second, vis);
        }
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<bool>> vis(3 * ROWS, vector<bool>(3 * COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == '/'){
                    vis[3 * row][3 * col + 2] = true;
                    vis[3 * row + 1][3 * col + 1] = true;
                    vis[3 * row + 2][3 * col] = true;
                }else if(grid[row][col] == '\\'){
                    vis[3 * row][3 * col] = true;
                    vis[3 * row + 1][3 * col + 1] = true;
                    vis[3 * row + 2][3 * col + 2] = true;
                }
            }
        }

        int regions = 0;
        for(int row = 0; row < 3 * ROWS; ++row){
            for(int col = 0; col < 3 * COLS; ++col){
                if(!vis[row][col]){
                    regions += 1;
                    dfs(row, col, vis);
                }
            }
        }

        return regions;
    }
};