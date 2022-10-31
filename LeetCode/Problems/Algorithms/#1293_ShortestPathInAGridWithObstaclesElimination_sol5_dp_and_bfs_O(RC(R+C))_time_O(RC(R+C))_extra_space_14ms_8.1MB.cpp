class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MAX_OBSTACLES = min(k, ROWS + COLS - 1);
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        const int INF = 1e8;
        enum CellType { EMPTY = 0, OBSTACLE = 1 };
        
        if(MAX_OBSTACLES >= ROWS + COLS - 3){
            return ROWS + COLS - 2;
        }
        
        // dp[row][col][k]: min steps from (0, 0) to (row, col)
        //                  when we remove k obstacles
        int dp[ROWS][COLS][MAX_OBSTACLES + 1];
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int obstacles = 0; obstacles <= MAX_OBSTACLES; ++obstacles){
                    dp[row][col][obstacles] = INF;
                }
            }
        }
        
        // state: (dp[row][col][obstacles], obstacles, row, col)
        using State = tuple<int, int, int, int>;
        queue<State> stateQueue;
        dp[0][0][0] = 0;
        stateQueue.push({dp[0][0][0], 0, 0, 0});
        
        while(!stateQueue.empty()){
            int minSteps, obstacles, row, col;
            tie(minSteps, obstacles, row, col) = stateQueue.front();
            stateQueue.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int nextObstacles = obstacles + (int)(grid[nextRow][nextCol] == CellType::OBSTACLE);
                    if(nextObstacles <= MAX_OBSTACLES && dp[row][col][obstacles] + 1 < dp[nextRow][nextCol][nextObstacles]){
                        dp[nextRow][nextCol][nextObstacles] = dp[row][col][obstacles] + 1;
                        stateQueue.push({dp[nextRow][nextCol][nextObstacles], nextObstacles, nextRow, nextCol});
                    }
                    if(nextRow == ROWS - 1 && nextCol == COLS - 1){
                        return dp[nextRow][nextCol][nextObstacles];
                    }
                }
            }
        }
        
        return -1;
    }
};