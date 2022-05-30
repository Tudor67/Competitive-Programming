class Solution {
private:
    enum Cell{ GRASS, FIRE, WALL };
    
    bool isPossible(vector<vector<int>>& grid, vector<vector<bool>>& vis, const int& MAX_TIME){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        queue<pair<int, int>> fireQ;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == Cell::FIRE){
                    fireQ.emplace(row, col);
                    vis[row][col] = true;
                }else if(grid[row][col] == Cell::WALL){
                    vis[row][col] = true;
                }else{
                    vis[row][col] = false;
                }
            }
        }
        
        for(int t = 0; t < MAX_TIME; ++t){
            for(int i = fireQ.size(); i >= 1; --i){
                int row = fireQ.front().first;
                int col = fireQ.front().second;
                fireQ.pop();
                
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                        if(!vis[nextRow][nextCol]){
                            fireQ.emplace(nextRow, nextCol);
                            vis[nextRow][nextCol] = true;
                        }
                    }
                }
            }
        }
        
        queue<pair<int, int>> myQ;
        if(!vis[0][0] && !vis[ROWS - 1][COLS - 1]){
            myQ.emplace(0, 0);
            vis[0][0] = true;
        }
        
        int currentTime = MAX_TIME;
        int safeHouseFireTime = -1;
        while(!myQ.empty()){
            // fire spread from (currentTime) to (currentTime + 1)
            for(int i = fireQ.size(); i >= 1; --i){
                int row = fireQ.front().first;
                int col = fireQ.front().second;
                fireQ.pop();
                
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                        if(!vis[nextRow][nextCol]){
                            fireQ.emplace(nextRow, nextCol);
                            vis[nextRow][nextCol] = true;
                            if(nextRow == ROWS - 1 && nextCol == COLS - 1){
                                safeHouseFireTime = currentTime + 1;
                            }
                        }
                    }
                }
            }
            
            // my moves from (currentTime) to (currentTime + 1)
            for(int i = myQ.size(); i >= 1; --i){
                int row = myQ.front().first;
                int col = myQ.front().second;
                myQ.pop();
                
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                        if(!vis[nextRow][nextCol]){
                            myQ.emplace(nextRow, nextCol);
                            vis[nextRow][nextCol] = true;
                            if(nextRow == ROWS - 1 && nextCol == COLS - 1){
                                return true;
                            }
                        }else if(nextRow == ROWS - 1 && nextCol == COLS - 1 && safeHouseFireTime == currentTime + 1){
                            return true;
                        }
                    }
                }
            }
            
            currentTime += 1;
        }
        
        return false;
    }
    
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MAX_TIME = ROWS * COLS + 1;
        
        int l = 0;
        int r = MAX_TIME;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(grid, vis, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        int res = r;
        if(res == 0 && !isPossible(grid, vis, 0)){
            res = -1;
        }else if(res == MAX_TIME){
            res = 1e9;
        }
        
        return res;
    }
};