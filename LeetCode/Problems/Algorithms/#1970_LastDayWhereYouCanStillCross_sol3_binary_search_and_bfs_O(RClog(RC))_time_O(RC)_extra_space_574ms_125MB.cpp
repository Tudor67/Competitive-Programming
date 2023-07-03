class Solution {
private:
    bool isPossible(vector<vector<bool>>& vis, vector<vector<int>>& cells, int lastDay){
        const int ROWS = vis.size();
        const int COLS = vis[0].size();
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                vis[row][col] = false;
            }
        }

        for(int i = 0; i < lastDay; ++i){
            vis[cells[i][0] - 1][cells[i][1] - 1] = true;
        }

        queue<pair<int, int>> q;
        for(int col = 0; col < COLS; ++col){
            if(!vis[0][col]){
                q.push({0, col});
                vis[0][col] = true;
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == ROWS - 1){
                return true;
            }

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && !vis[nextRow][nextCol]){
                    q.push({nextRow, nextCol});
                    vis[nextRow][nextCol] = true;
                }
            }
        }

        return false;
    }

public:
    int latestDayToCross(int ROWS, int COLS, vector<vector<int>>& cells) {
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));

        int l = 0;
        int r = cells.size();
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(vis, cells, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};