class Solution {
private:
    const int WATER = 0;
    const int LAND = 1;
    
    int computeAreaAndUpdateVis(int startRow, int startCol, vector<vector<bool>>& vis){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const int ROWS = vis.size();
        const int COLS = vis[0].size();
        
        queue<pair<int, int>> q;
        q.emplace(startRow, startCol);
        vis[startRow][startCol] = true;
        
        int area = 0;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            area += 1;
            
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
        
        return area;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == WATER){
                    vis[row][col] = true;
                }else{
                    vis[row][col] = false;
                }
            }
        }
        
        int maxArea = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == LAND && !vis[row][col]){
                    int area = computeAreaAndUpdateVis(row, col, vis);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};