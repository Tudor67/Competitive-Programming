class Solution {
private:
    enum CellType { WATER = '0', LAND = '1' };
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(int row, int col, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        if(!(0 <= row && row < ROWS && 0 <= col && col < COLS)){
            return;
        }

        if(vis[row][col] || grid[row][col] == CellType::WATER){
            return;
        }

        vis[row][col] = true;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            dfs(nextRow, nextCol, vis, grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int islands = 0;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == CellType::LAND && !vis[row][col]){
                    islands += 1;
                    dfs(row, col, vis, grid);
                }
            }
        }

        return islands;
    }
};