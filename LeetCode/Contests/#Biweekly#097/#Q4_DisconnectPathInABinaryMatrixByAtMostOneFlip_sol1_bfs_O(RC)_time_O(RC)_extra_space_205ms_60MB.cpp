class Solution {
private:
    void bfs(vector<vector<int>>& grid, vector<pair<int, int>>& path){
        static const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}};
        static const int INF = 1e8;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(nextRow < ROWS && nextCol < COLS && grid[nextRow][nextCol] == 1 && dist[nextRow][nextCol] == INF){
                    dist[nextRow][nextCol] = dist[row][col] + 1;
                    q.push({nextRow, nextCol});
                }
            }
        }
        
        path.clear();
        if(dist[ROWS - 1][COLS - 1] != INF){
            int row = ROWS - 1;
            int col = COLS - 1;
            while(pair<int, int>{row, col} != pair<int, int>{0, 0}){
                path.push_back({row, col});
                if(col - 1 >= 0 && dist[row][col - 1] + 1 == dist[row][col]){
                    col -= 1;
                }else{
                    row -= 1;
                }
            }
            path.erase(path.begin());
        }
    }
    
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        // Step 0: special case when the number of cells <= 2
        //         you cannot make the matrix disconnected => return false
        if(ROWS * COLS <= 2){
            return false;
        }
        
        // Step 1: bfs from {0, 0} to {ROWS - 1, COLS - 1}
        //         try to save a valid path with coordinates closer to the border of the grid
        //         if there is no valid path => the matrix is disconnected => return true
        vector<pair<int, int>> path;
        bfs(grid, path);
        
        if(path.empty()){
            return true;
        }

        // Step 2: remove the path from Step 1 (i.e. mark with 0 all path cells)
        //         bfs from {0, 0} to {ROWS - 1, COLS - 1} on the modified grid2
        //         if there is no valid path => the matrix is disconnected => return true
        //         why? if the initial matrix can be disconnected with at most one flip
        //              it means that there is at least one cell which is common for all valid paths from
        //              {0, 0} to {ROWS - 1, COLS - 1}
        //              by removing a valid path close to the border (path coordinates from Step 1)
        //              we remove all common cells of the valid paths
        //              as a result, the new matrix should be disconnected
        vector<vector<int>> grid2 = grid;
        for(const pair<int, int>& P: path){
            int row = P.first;
            int col = P.second;
            grid2[row][col] = 0;
        }

        path.clear();
        bfs(grid2, path);
        
        if(path.empty()){
            return true;
        }
        
        return false;
    }
};