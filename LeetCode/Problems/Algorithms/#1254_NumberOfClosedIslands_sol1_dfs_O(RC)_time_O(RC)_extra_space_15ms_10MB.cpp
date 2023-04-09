class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void dfs(int row, int col, vector<vector<bool>>& vis){
        const int ROWS = vis.size();
        const int COLS = vis[0].size();
        if(row < 0 || ROWS <= row || col < 0 || COLS <= col || vis[row][col]){
            return;
        }
        vis[row][col] = true;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            dfs(nextRow, nextCol, vis);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0){
                    vis[row][col] = false;
                }else{
                    vis[row][col] = true;
                }
            }
        }

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1){
                    dfs(row, col, vis);
                }
            }
        }

        int closedIslands = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(!vis[row][col]){
                    dfs(row, col, vis);
                    closedIslands += 1;
                }
            }
        }

        return closedIslands;
    }
};