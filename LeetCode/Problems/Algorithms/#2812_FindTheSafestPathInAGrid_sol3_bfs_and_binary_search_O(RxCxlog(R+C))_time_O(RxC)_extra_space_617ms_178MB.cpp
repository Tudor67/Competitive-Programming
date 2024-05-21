class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int INF = 1e9;

    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void computeSafeness(vector<vector<int>>& grid, vector<vector<int>>& safeness){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col]){
                    safeness[row][col] = 0;
                    q.push({row, col});
                }else{
                    safeness[row][col] = INF;
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
                if(isInside(nextRow, nextCol, ROWS, COLS) && safeness[nextRow][nextCol] == INF){
                    safeness[nextRow][nextCol] = safeness[row][col] + 1;
                    q.push({nextRow, nextCol});
                }
            }
        }
    }

    bool isPossible(const pair<int, int>& SRC, const pair<int, int>& DEST,
                    vector<vector<int>>& safeness, const int THRESHOLD){
        const int ROWS = safeness.size();
        const int COLS = safeness[0].size();

        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        queue<pair<int, int>> q;
        if(safeness[SRC.first][SRC.second] >= THRESHOLD){
            vis[SRC.first][SRC.second] = true;
            q.push(SRC);
        }

        while(!q.empty() && !vis[DEST.first][DEST.second]){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS) &&
                   safeness[nextRow][nextCol] >= THRESHOLD &&
                   !vis[nextRow][nextCol]){
                    vis[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol});
                }
            }
        }

        return vis[DEST.first][DEST.second];
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        // Step 1: compute safeness factor of each cell
        vector<vector<int>> safeness(ROWS, vector<int>(COLS));
        computeSafeness(grid, safeness);

        // Step 2: binary search the max safeness factor of all paths from (0, 0) to (ROWS - 1, COLS - 1)
        int l = 0;
        int r = min(safeness[0][0], safeness[ROWS - 1][COLS - 1]);
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible({0, 0}, {ROWS - 1, COLS - 1}, safeness, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};