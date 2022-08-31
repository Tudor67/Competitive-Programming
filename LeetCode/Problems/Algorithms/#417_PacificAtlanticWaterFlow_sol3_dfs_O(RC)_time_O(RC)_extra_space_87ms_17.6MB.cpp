class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& vis){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        if(vis[row][col]){
            return;
        }
        
        vis[row][col] = true;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                if(heights[row][col] <= heights[nextRow][nextCol]){
                    dfs(nextRow, nextCol, heights, vis);
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
                    dfs(row, col, heights, pacificVis);
                }
                if(row == ROWS - 1 || col == COLS - 1){
                    dfs(row, col, heights, atlanticVis);
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