class Solution {
private:
    const int LAND = 0;
    const int WATER = 1;
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isInside(int row, int col, vector<vector<int>>& grid){
        return (0 <= row && row < (int)grid.size() && 0 <= col && col < (int)grid[0].size());
    }

    void dfs(int row, int col, vector<vector<bool>>& vis, bool& isClosedIsland, vector<vector<int>>& grid){
        if(!isInside(row, col, grid)){
            isClosedIsland = false;
            return;
        }
        if(vis[row][col] || grid[row][col] == WATER){
            return;
        }
        vis[row][col] = true;
        for(const auto& [rowDir, colDir]: DIRECTIONS){
            dfs(row + rowDir, col + colDir, vis, isClosedIsland, grid);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int closedIslandsCount = 0;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(vis[row][col] || grid[row][col] == WATER){
                    continue;
                }

                bool isClosedIsland = true;
                dfs(row, col, vis, isClosedIsland, grid);
                if(isClosedIsland){
                    ++closedIslandsCount;
                }
            }
        }

        return closedIslandsCount;
    }
};