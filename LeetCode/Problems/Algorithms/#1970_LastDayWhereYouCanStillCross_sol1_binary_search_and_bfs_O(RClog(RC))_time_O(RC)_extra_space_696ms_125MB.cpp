class Solution {
private:
    bool isPossible(vector<vector<bool>>& vis, const int& ROWS, const int& COLS, vector<vector<int>>& cells, const int& STEPS){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        for(int row = 1; row <= ROWS; ++row){
            fill(vis[row].begin(), vis[row].end(), false);
        }
        
        for(int i = 0; i < STEPS; ++i){
            int row = cells[i][0];
            int col = cells[i][1];
            vis[row][col] = true;
        }
        
        queue<pair<int, int>> q;
        for(int col = 1; col <= COLS; ++col){
            if(!vis[1][col]){
                q.emplace(1, col);
                vis[1][col] = true;
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row == ROWS){
                return true;
            }
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(1 <= nextRow && nextRow <= ROWS && 1 <= nextCol && nextCol <= COLS && !vis[nextRow][nextCol]){
                    q.emplace(nextRow, nextCol);
                    vis[nextRow][nextCol] = true;
                }
            }
        }
        
        return false;
    }
    
public:
    int latestDayToCross(int ROWS, int COLS, vector<vector<int>>& cells) {
        vector<vector<bool>> vis(ROWS + 2, vector<bool>(COLS + 2));
        int l = 0;
        int r = ROWS * COLS;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(vis, ROWS, COLS, cells, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
};