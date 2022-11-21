class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int ROWS = maze.size();
        const int COLS = maze[0].size();
        const int START_ROW = entrance[0];
        const int START_COL = entrance[1];
        const int INF = 1e9;
        const char WALL_CELL = '+';
        const char EMPTY_CELL = '.';
        const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        q.push({START_ROW, START_COL});
        dist[START_ROW][START_COL] = 0;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(maze[nextRow][nextCol] == EMPTY_CELL && dist[row][col] + 1 < dist[nextRow][nextCol]){
                        dist[nextRow][nextCol] = dist[row][col] + 1;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
        
        int res = INF;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1){
                    if(dist[row][col] != INF && pair<int, int>{row, col} != pair<int, int>{START_ROW, START_COL}){
                        res = min(res, dist[row][col]);
                    }
                }
            }
        }
        
        if(res == INF){
            res = -1;
        }
        
        return res;
    }
};