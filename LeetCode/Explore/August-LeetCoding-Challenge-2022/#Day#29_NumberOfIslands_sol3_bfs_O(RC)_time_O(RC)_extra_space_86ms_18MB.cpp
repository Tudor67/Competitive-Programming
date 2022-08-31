class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    void bfs(int srcRow, int srcCol, vector<vector<bool>>& vis){
        const int ROWS = vis.size();
        const int COLS = vis[0].size();
        
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
                    if(!vis[nextRow][nextCol]){
                        vis[nextRow][nextCol] = true;
                        q.emplace(nextRow, nextCol);
                    }
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
                    bfs(row, col, vis);
                }
            }
        }
        
        return islands;
    }
};