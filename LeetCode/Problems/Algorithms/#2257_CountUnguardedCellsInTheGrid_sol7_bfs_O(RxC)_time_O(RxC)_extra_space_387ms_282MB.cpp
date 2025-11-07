class Solution {
public:
    int countUnguarded(int ROWS, int COLS, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        using DirRowCol = array<int, 3>;
        queue<DirRowCol> q;
        vector<vector<vector<bool>>> vis(4, vector<vector<bool>>(ROWS, vector<bool>(COLS, false)));
        for(vector<int>& guard: guards){
            int row = guard[0];
            int col = guard[1];
            for(int dirIdx = 0; dirIdx < (int)DIRECTIONS.size(); ++dirIdx){
                q.push({dirIdx, row, col});
                vis[dirIdx][row][col] = true;
            }
        }

        for(vector<int>& wall: walls){
            int row = wall[0];
            int col = wall[1];
            for(int dirIdx = 0; dirIdx < (int)DIRECTIONS.size(); ++dirIdx){
                vis[dirIdx][row][col] = true;
            }
        }

        while(!q.empty()){
            int dirIdx = q.front()[0];
            int row = q.front()[1];
            int col = q.front()[2];
            q.pop();

            int nextRow = row + DIRECTIONS[dirIdx].first;
            int nextCol = col + DIRECTIONS[dirIdx].second;

            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
               !vis[dirIdx][nextRow][nextCol]){
                q.push({dirIdx, nextRow, nextCol});
                vis[dirIdx][nextRow][nextCol] = true;
            }
        }

        int res = ROWS * COLS;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(vis[0][row][col] || vis[1][row][col] || vis[2][row][col] || vis[3][row][col]){
                    res -= 1;
                }
            }
        }

        return res;
    }
};