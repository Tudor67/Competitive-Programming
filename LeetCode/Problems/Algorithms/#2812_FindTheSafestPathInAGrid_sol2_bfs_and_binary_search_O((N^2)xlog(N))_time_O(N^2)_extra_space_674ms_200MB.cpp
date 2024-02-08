class Solution {
private:
    enum Cell { EMPTY = 0, THIEF = 1 };
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int INF = 1e9;
    
    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void computeThiefDist(vector<vector<int>>& grid, vector<vector<int>>& thiefDist){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        thiefDist.assign(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == Cell::THIEF){
                    q.push({row, col});
                    thiefDist[row][col] = 0;
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
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    if(thiefDist[row][col] + 1 < thiefDist[nextRow][nextCol]){
                        thiefDist[nextRow][nextCol] = thiefDist[row][col] + 1;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
    }

    bool isPossible(vector<vector<int>>& thiefDist, const int MIN_THIEF_DIST_THRESHOLD){
        const int ROWS = thiefDist.size();
        const int COLS = thiefDist[0].size();
        
        if(thiefDist[0][0] < MIN_THIEF_DIST_THRESHOLD){
            return false;
        }
        
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        vis[0][0] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row == ROWS - 1 && col == COLS - 1){
                return true;
            }
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS) && !vis[nextRow][nextCol]){
                    if(thiefDist[nextRow][nextCol] >= MIN_THIEF_DIST_THRESHOLD){
                        vis[nextRow][nextCol] = true;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
        
        return false;
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> thiefDist;
        computeThiefDist(grid, thiefDist);
        
        int l = 0;
        int r = thiefDist[0][0];
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(thiefDist, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};