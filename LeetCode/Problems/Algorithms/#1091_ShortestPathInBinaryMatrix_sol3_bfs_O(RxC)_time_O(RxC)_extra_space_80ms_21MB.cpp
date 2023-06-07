class Solution {
private:
    int bfs(pair<int, int> srcCell, pair<int, int> destCell, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1},
                                                   {0, -1}, {0, 1},
                                                   {1, -1}, {1, 0}, {1, 1}};
        
        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        if(grid[srcCell.first][srcCell.second] == 0){
            q.push(srcCell);
            dist[srcCell.first][srcCell.second] = 1;
        }

        while(!q.empty() && dist[destCell.first][destCell.second] == INF){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(grid[nextRow][nextCol] == 0 && dist[row][col] + 1 < dist[nextRow][nextCol]){
                        dist[nextRow][nextCol] = dist[row][col] + 1;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }

        if(dist[destCell.first][destCell.second] != INF){
            return dist[destCell.first][destCell.second];
        }

        return -1;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return bfs({0, 0}, {ROWS - 1, COLS - 1}, grid);
    }
};