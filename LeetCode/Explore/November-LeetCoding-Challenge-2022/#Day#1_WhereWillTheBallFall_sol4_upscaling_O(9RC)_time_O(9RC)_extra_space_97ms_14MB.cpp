class Solution {
private:
    int dfs(int row, int col, vector<vector<bool>>& vis){
        static const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {1, 0}};
        const int ROWS = vis.size();
        const int COLS = vis[0].size();
        
        vis[row][col] = true;
        
        if(row == ROWS - 1){
            return col;
        }
        
        int finalCol = -3;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && !vis[nextRow][nextCol]){
                finalCol = max(finalCol, dfs(nextRow, nextCol, vis));
            }
        }
        
        return finalCol;
    }
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<bool>> vis(3 * ROWS, vector<bool>(3 * COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int upscaledRow = 3 * row;
                int upscaledCol = 3 * col;
                if(grid[row][col] == -1){
                    vis[upscaledRow][upscaledCol + 2] = true;
                    vis[upscaledRow + 1][upscaledCol + 1] = true;
                    vis[upscaledRow + 2][upscaledCol] = true;
                }else if(grid[row][col] == 1){
                    vis[upscaledRow][upscaledCol] = true;
                    vis[upscaledRow + 1][upscaledCol + 1] = true;
                    vis[upscaledRow + 2][upscaledCol + 2] = true;
                }
            }
        }
        
        vector<int> answer(COLS);
        for(int col = 0; col < COLS; ++col){
            int upscaledRow = 0;
            int upscaledCol = 3 * col + 1;
            answer[col] = dfs(upscaledRow, upscaledCol, vis) / 3;
        }
        
        return answer;
    }
};