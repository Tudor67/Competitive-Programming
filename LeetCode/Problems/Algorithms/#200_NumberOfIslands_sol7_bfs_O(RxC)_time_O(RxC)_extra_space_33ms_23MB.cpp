class Solution {
private:
    enum CellType { WATER = '0', LAND = '1' };
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void bfs(int srcRow, int srcCol, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        queue<pair<int, int>> q;
        if(isInside(srcRow, srcCol, ROWS, COLS) &&
           !vis[srcRow][srcCol] && grid[srcRow][srcCol] == CellType::LAND){
            vis[srcRow][srcCol] = true;
            q.push({srcRow, srcCol});
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS) &&
                   !vis[nextRow][nextCol] && grid[nextRow][nextCol] == CellType::LAND){
                    vis[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol});
                }
            }
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
                    bfs(row, col, vis, grid);
                }
            }
        }

        return islands;
    }
};