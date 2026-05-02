class Solution {
private:
    const vector<vector<pair<int, int>>> SHAPES = {
        {},
        {{1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {2, 1}},
        {{1, 1}, {1, 2}, {2, 1}},
        {{0, 1}, {1, 0}, {1, 1}},
        {{0, 1}, {1, 1}, {1, 2}}
    };
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool dfs(int row, int col, vector<vector<bool>>& ok, vector<vector<bool>>& vis){
        const int ROWS = ok.size();
        const int COLS = ok[0].size();
        if(row == 1 && col == 1){
            return true;
        }
        if(!(0 <= row && row < ROWS && 0 <= col && col < COLS)){
            return false;
        }
        if(!ok[row][col]){
            return false;
        }
        if(vis[row][col]){
            return false;
        }
        vis[row][col] = true;
        for(const auto& [rowDir, colDir]: DIRECTIONS){
            if(dfs(row + rowDir, col + colDir, ok, vis)){
                return true;
            }
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<bool>> ok(3 * ROWS, vector<bool>(3 * COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(const auto& [dr, dc]: SHAPES[grid[row][col]]){
                    ok[3 * row + dr][3 * col + dc] = true;
                }
            }
        }
        
        vector<vector<bool>> vis(3 * ROWS, vector<bool>(3 * COLS, false));
        return dfs(3 * ROWS - 2, 3 * COLS - 2, ok, vis);
    }
};