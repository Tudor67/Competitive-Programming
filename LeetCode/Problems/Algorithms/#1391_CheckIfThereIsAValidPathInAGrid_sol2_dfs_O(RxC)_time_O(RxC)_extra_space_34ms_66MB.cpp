class Solution {
private:
    const vector<vector<int>> VALID_DIR_INDICES = {
        {},
        {1, 3},
        {0, 2},
        {2, 3},
        {1, 2},
        {0, 3},
        {0, 1}
    };
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool isInside(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    bool dfs(int row, int col, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        if(row == 0 && col == 0){
            return true;
        }
        if(vis[row][col]){
            return false;
        }
        vis[row][col] = true;
        for(int dirIdx: VALID_DIR_INDICES[grid[row][col]]){
            int nextRow = row + DIRECTIONS[dirIdx].first;
            int nextCol = col + DIRECTIONS[dirIdx].second;
            int revDirIdx = (dirIdx + 2) % 4;
            if(isInside(nextRow, nextCol, grid)){
                const auto& V = VALID_DIR_INDICES[grid[nextRow][nextCol]];
                if((V[0] == revDirIdx || V[1] == revDirIdx) &&
                   dfs(nextRow, nextCol, vis, grid)){
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        return dfs(ROWS - 1, COLS - 1, vis, grid);
    }
};