class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    void bfs(int srcRow, int srcCol, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        queue<pair<int, int>> q;
        q.emplace(srcRow, srcCol);
        vis[srcRow][srcCol] = true;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(!vis[nextRow][nextCol] && grid[nextRow][nextCol] == grid[row][col]){
                        vis[nextRow][nextCol] = true;
                        q.emplace(nextRow, nextCol);
                    }
                }
            }
        }
    }
    
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int srcRow, int srcCol, int color) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        bfs(srcRow, srcCol, grid, vis);
        
        vector<vector<int>> res = grid;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(vis[row][col]){
                    if(row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1){
                        res[row][col] = color;
                    }else{
                        for(const pair<int, int>& DIRECTION: DIRECTIONS){
                            int nextRow = row + DIRECTION.first;
                            int nextCol = col + DIRECTION.second;
                            if(!vis[nextRow][nextCol]){
                                res[row][col] = color;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        return res;
    }
};