class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isInside(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void dfs(int row, int col, vector<vector<bool>>& vis, vector<vector<int>>& heights){
        vis[row][col] = true;
        for(auto [rowDir, colDir]: DIRECTIONS){
            int nextRow = row + rowDir;
            int nextCol = col + colDir;
            if(isInside(nextRow, nextCol, heights) && !vis[nextRow][nextCol] &&
               heights[row][col] <= heights[nextRow][nextCol]){
                dfs(nextRow, nextCol, vis, heights);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();

        vector<vector<bool>> visP(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> visA(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 || col == 0){
                    dfs(row, col, visP, heights);
                }
                if(row == ROWS - 1 || col == COLS - 1){
                    dfs(row, col, visA, heights);
                }
            }
        }

        vector<vector<int>> res;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(visA[row][col] && visP[row][col]){
                    res.push_back({row, col});
                }
            }
        }

        return res;
    }
};