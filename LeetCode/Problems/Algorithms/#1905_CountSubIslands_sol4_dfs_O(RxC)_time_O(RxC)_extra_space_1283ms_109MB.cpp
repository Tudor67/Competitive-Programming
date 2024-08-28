class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    bool isInside(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2,
             vector<vector<bool>>& vis2, bool& isSubIsland){
        if(!isInside(row, col, grid2) || grid2[row][col] == 0 || vis2[row][col]){
            return;
        }
        if(grid1[row][col] == 0){
            isSubIsland = false;
        }
        vis2[row][col] = true;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            dfs(row + DIRECTION.first, col + DIRECTION.second, grid1, grid2, vis2, isSubIsland);
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int ROWS = grid1.size();
        const int COLS = grid1[0].size();

        int subIslands = 0;
        vector<vector<bool>> vis2(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid2[row][col] == 1 && !vis2[row][col]){
                    bool isSubIsland = true;
                    dfs(row, col, grid1, grid2, vis2, isSubIsland);
                    subIslands += (int)isSubIsland;
                }
            }
        }

        return subIslands;
    }
};