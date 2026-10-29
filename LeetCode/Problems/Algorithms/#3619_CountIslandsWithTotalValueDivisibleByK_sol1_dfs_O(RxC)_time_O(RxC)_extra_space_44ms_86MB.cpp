class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(int row, int col, vector<vector<bool>>& vis, int& sumRem, vector<vector<int>>& grid, int k){
        if(!(0 <= row && row < (int)grid.size() && 0 <= col && col < (int)grid[0].size())){
            return;
        }
        if(grid[row][col] == 0 || vis[row][col]){
            return;
        }
        vis[row][col] = true;
        sumRem = (sumRem + grid[row][col]) % k;
        for(const auto& [rowDir, colDir]: DIRECTIONS){
            dfs(row + rowDir, col + colDir, vis, sumRem, grid, k);
        }
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int validIslands = 0;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] > 0 && !vis[row][col]){
                    int sumRem = 0;
                    dfs(row, col, vis, sumRem, grid, k);

                    if(sumRem == 0){
                        ++validIslands;
                    }
                }
            }
        }

        return validIslands;
    }
};