class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int INF = 5e8;
    const char PLAYER = 'S';
    const char BOX = 'B';
    const char TARGET = 'T';
    const char WALL = '#';
    
    bool isInside(int row, int col, const int& ROWS, const int& COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }
    
    bool isAccessible(int srcRow, int srcCol, int destRow, int destCol, int blockedRow, int blockedCol,
                      vector<vector<char>>& grid, vector<vector<bool>>& vis){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                vis[row][col] = false;
            }
        }
        
        queue<pair<int, int>> q;
        q.emplace(srcRow, srcCol);
        vis[srcRow][srcCol] = true;
        vis[blockedRow][blockedCol] = true;
        
        while(!q.empty() && !vis[destRow][destCol]){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS) && grid[nextRow][nextCol] != WALL && !vis[nextRow][nextCol]){
                    q.emplace(nextRow, nextCol);
                    vis[nextRow][nextCol] = true;
                }
            }
        }
        
        return vis[destRow][destCol];
    }
    
public:
    int minPushBox(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        // Step 1: extract (PLAYER_ROW, PLAYER_COL), (BOX_ROW, BOX_COL) and (TARGET_ROW, TARGET_COL)
        int PLAYER_ROW = -1;
        int PLAYER_COL = -1;
        int BOX_ROW = -1;
        int BOX_COL = -1;
        int TARGET_ROW = -1;
        int TARGET_COL = -1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == PLAYER){
                    PLAYER_ROW = row;
                    PLAYER_COL = col;
                }if(grid[row][col] == BOX){
                    BOX_ROW = row;
                    BOX_COL = col;
                }else if(grid[row][col] == TARGET){
                    TARGET_ROW = row;
                    TARGET_COL = col;
                }
            }
        }
        
        // Step 2: compute the shortest path from (BOX_ROW, BOX_COL) to (TARGET_ROW, TARGET_COL) following the rules
        // A state is defined as (minDist[currentBoxRow][currentBoxCol], currentBoxRow, currentBoxCol, currentBoxDirIdx)
        vector<vector<vector<int>>> minDist(ROWS, vector<vector<int>>(COLS, vector<int>(DIRECTIONS.size(), INF)));
        set<tuple<int, int, int, int>> states;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        
        for(int dirIdx = 0; dirIdx < (int)DIRECTIONS.size(); ++dirIdx){
            int playerRow = BOX_ROW - DIRECTIONS[dirIdx].first;
            int playerCol = BOX_COL - DIRECTIONS[dirIdx].second;
            if(isInside(playerRow, playerCol, ROWS, COLS) && grid[playerRow][playerCol] != WALL &&
               isAccessible(PLAYER_ROW, PLAYER_COL, playerRow, playerCol, BOX_ROW, BOX_COL, grid, vis)){
                // (playerRow, playerCol) is a neighbor of (BOX_ROW, BOX_COL),
                // which is accessible from (PLAYER_ROW, PLAYER_COL)
                minDist[BOX_ROW][BOX_COL][dirIdx] = 0;
                states.emplace(minDist[BOX_ROW][BOX_COL][dirIdx], BOX_ROW, BOX_COL, dirIdx);
            }
        }
        
        while(!states.empty()){
            int row, col, dirIdx;
            tie(ignore, row, col, dirIdx) = *states.begin();
            states.erase(states.begin());
            
            int nextRow = row + DIRECTIONS[dirIdx].first;
            int nextCol = col + DIRECTIONS[dirIdx].second;
            
            if(isInside(nextRow, nextCol, ROWS, COLS) && grid[nextRow][nextCol] != WALL){
                for(int nextDirIdx = 0; nextDirIdx < (int)DIRECTIONS.size(); ++nextDirIdx){
                    int playerRow = row - DIRECTIONS[dirIdx].first;
                    int playerCol = col - DIRECTIONS[dirIdx].second;
                    int nextPlayerRow = nextRow - DIRECTIONS[nextDirIdx].first;
                    int nextPlayerCol = nextCol - DIRECTIONS[nextDirIdx].second;
                    if(isInside(nextPlayerRow, nextPlayerCol, ROWS, COLS) && grid[nextPlayerRow][nextPlayerCol] != WALL &&
                       minDist[row][col][dirIdx] + 1 < minDist[nextRow][nextCol][nextDirIdx] &&
                       isAccessible(playerRow, playerCol, nextPlayerRow, nextPlayerCol, nextRow, nextCol, grid, vis)){
                        states.erase({minDist[nextRow][nextCol][nextDirIdx], nextRow, nextCol, nextDirIdx});
                        minDist[nextRow][nextCol][nextDirIdx] = minDist[row][col][dirIdx] + 1;
                        states.emplace(minDist[nextRow][nextCol][nextDirIdx], nextRow, nextCol, nextDirIdx);
                    }
                }
            }
        }
        
        int res = *min_element(minDist[TARGET_ROW][TARGET_COL].begin(), minDist[TARGET_ROW][TARGET_COL].end());
        if(res == INF){
            res = -1;
        }
        
        return res;
    }
};