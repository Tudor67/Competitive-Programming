class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isPossible(vector<vector<int>>& maxTime, int threshold){
        const int ROWS = maxTime.size();
        const int COLS = maxTime[0].size();

        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        queue<pair<int, int>> q;
        for(int col = 0; col < COLS; ++col){
            if(maxTime[0][col] >= threshold){
                vis[0][col] = true;
                q.push({0, col});
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == ROWS - 1){
                return true;
            }

            for(auto [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   !vis[nextRow][nextCol] && maxTime[nextRow][nextCol] >= threshold){
                    vis[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol});
                }
            }
        }

        return false;
    }

public:
    int latestDayToCross(int ROWS, int COLS, vector<vector<int>>& cells) {
        vector<vector<int>> maxTime(ROWS, vector<int>(COLS));
        for(int i = 0; i < (int)cells.size(); ++i){
            maxTime[cells[i][0] - 1][cells[i][1] - 1] = i;
        }

        int l = 0;
        int r = ROWS * COLS;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(maxTime, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};