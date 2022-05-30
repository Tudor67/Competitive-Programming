class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int INF = 1e9;
    
    enum Cell{ GRASS, FIRE, WALL };
    
    void computeMinFireTime(vector<vector<int>>& grid, vector<vector<int>>& minFireTime){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == Cell::FIRE){
                    q.emplace(row, col);
                    minFireTime[row][col] = 0;
                }else if(grid[row][col] == Cell::WALL){
                    minFireTime[row][col] = 0;
                }else{
                    minFireTime[row][col] = INF;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(minFireTime[row][col] + 1 < minFireTime[nextRow][nextCol]){
                        minFireTime[nextRow][nextCol] = minFireTime[row][col] + 1;
                        q.emplace(nextRow, nextCol);
                    }
                }
            }
        }
    }
    
    bool isPossible(vector<vector<int>>& minFireTime, vector<vector<bool>>& vis, const int& START_TIME){
        const int ROWS = minFireTime.size();
        const int COLS = minFireTime[0].size();
        
        if(minFireTime[0][0] <= START_TIME || minFireTime[ROWS - 1][COLS - 1] <= START_TIME){
            return false;
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                vis[row][col] = false;
            }
        }
        
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        int currentTime = START_TIME;
        while(!q.empty()){
            // my moves from (currentTime) to (currentTime + 1)
            for(int i = q.size(); i >= 1; --i){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                        if(!vis[nextRow][nextCol] && currentTime + 1 < minFireTime[nextRow][nextCol]){
                            q.emplace(nextRow, nextCol);
                            vis[nextRow][nextCol] = true;
                        }
                        if(nextRow == ROWS - 1 && nextCol == COLS - 1 && currentTime + 1 <= minFireTime[nextRow][nextCol]){
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
        
        vector<vector<int>> minFireTime(ROWS, vector<int>(COLS));
        computeMinFireTime(grid, minFireTime);
        
        int l = 0;
        int r = MAX_TIME;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(minFireTime, vis, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        int res = r;
        if(res == 0 && !isPossible(minFireTime, vis, 0)){
            res = -1;
        }else if(res == MAX_TIME){
            res = 1e9;
        }
        
        return res;
    }
};