class Solution {
private:
    bool isInside(int row, int col, const int& ROWS, const int& COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int startRow = 0;
        int startCol = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col]){
                    startRow = row;
                    startCol = col;
                }
            }
        }
        
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        vis[startRow][startCol] = true;
        
        int p = 4;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS) && grid[nextRow][nextCol]){
                    if(vis[nextRow][nextCol]){
                        p -= 1;
                    }else{
                        p += 3;
                        q.push({nextRow, nextCol});
                        vis[nextRow][nextCol] = true;
                    }
                }
            }
        }
        
        return p;
    }
};