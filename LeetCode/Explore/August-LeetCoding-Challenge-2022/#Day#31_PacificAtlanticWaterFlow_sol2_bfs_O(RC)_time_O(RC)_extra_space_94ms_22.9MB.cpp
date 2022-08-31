class Solution {
private:
    void bfs(int srcRow, int srcCol, vector<vector<int>>& heights, vector<vector<bool>>& vis){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        if(vis[srcRow][srcCol]){
            return;
        }
        
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
                    if(!vis[nextRow][nextCol] && heights[row][col] <= heights[nextRow][nextCol]){
                        vis[nextRow][nextCol] = true;
                        q.emplace(nextRow, nextCol);
                    }
                }
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        vector<vector<bool>> pacificVis(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlanticVis(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 || col == 0){
                    bfs(row, col, heights, pacificVis);
                }
                if(row == ROWS - 1 || col == COLS - 1){
                    bfs(row, col, heights, atlanticVis);
                }
            }
        }
        
        vector<vector<int>> res;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(pacificVis[row][col] && atlanticVis[row][col]){
                    res.push_back({row, col});
                }
            }
        }
        
        return res;
    }
};