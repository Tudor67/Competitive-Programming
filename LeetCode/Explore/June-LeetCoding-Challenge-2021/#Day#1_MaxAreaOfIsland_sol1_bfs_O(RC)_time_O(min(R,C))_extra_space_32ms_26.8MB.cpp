class Solution {
private:
    int bfs(int row, int col, vector<vector<int>>& grid, const int& CC_ID){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int area = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = CC_ID;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            area += 1;
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && grid[nextRow][nextCol] == 1){
                    q.push({nextRow, nextCol});
                    grid[nextRow][nextCol] = CC_ID;
                }
            }
        }
        
        return area;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int maxArea = 0;
        int ccID = 1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    ccID += 1;
                    int area = bfs(row, col, grid, ccID);
                    maxArea = max(area, maxArea);
                }
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] >= 1){
                    grid[row][col] = 1;
                }
            }
        }
        
        return maxArea;
    }
};