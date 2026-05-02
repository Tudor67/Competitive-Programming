class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    bool isInside(int row, int col, vector<vector<char>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    bool dfs(int pRow, int pCol, int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        vis[row][col] = true;
        for(const auto& [rowDir, colDir]: DIRECTIONS){
            int nextRow = row + rowDir;
            int nextCol = col + colDir;

            if(!isInside(nextRow, nextCol, grid) ||
               grid[nextRow][nextCol] != grid[row][col]){
                continue;
            }

            if(vis[nextRow][nextCol]){
                if(nextRow != pRow || nextCol != pCol){
                    return true;
                }
            }else if(dfs(row, col, nextRow, nextCol, grid, vis)){
                return true;
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(!vis[row][col] && dfs(-1, -1, row, col, grid, vis)){
                    return true;
                }
            }
        }

        return false;
    }
};