class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    void dfs(int row, int col, vector<vector<bool>>& vis){
        const int ROWS = vis.size();
        const int COLS = vis[0].size();
        
        vis[row][col] = true;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                if(!vis[nextRow][nextCol]){
                    dfs(nextRow, nextCol, vis);
                }
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == '0'){
                    vis[row][col] = true;
                }else{
                    vis[row][col] = false;
                }
            }
        }
        
        int islands = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(!vis[row][col]){
                    islands += 1;
                    dfs(row, col, vis);
                }
            }
        }
        
        return islands;
    }
};