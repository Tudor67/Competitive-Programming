class Solution {
public:
    int countUnguarded(int ROWS, int COLS, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        using RowColDir = array<int, 3>;
        queue<RowColDir> q;
        set<RowColDir> vis;
        for(vector<int>& guard: guards){
            int row = guard[0];
            int col = guard[1];
            for(int dirIdx = 0; dirIdx < (int)DIRECTIONS.size(); ++dirIdx){
                q.push({row, col, dirIdx});
                vis.insert({row, col, dirIdx});
            }
        }

        for(vector<int>& wall: walls){
            int row = wall[0];
            int col = wall[1];
            for(int dirIdx = 0; dirIdx < (int)DIRECTIONS.size(); ++dirIdx){
                vis.insert({row, col, dirIdx});
            }
        }

        int res = ROWS * COLS - (int)walls.size();
        vector<vector<bool>> guarded(ROWS, vector<bool>(COLS, false));
        while(!q.empty()){
            int row = q.front()[0];
            int col = q.front()[1];
            int dirIdx = q.front()[2];
            q.pop();

            if(!guarded[row][col]){
                res -= 1;
                guarded[row][col] = true;
            }

            int nextRow = row + DIRECTIONS[dirIdx].first;
            int nextCol = col + DIRECTIONS[dirIdx].second;

            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
               !vis.count({nextRow, nextCol, dirIdx})){
                q.push({nextRow, nextCol, dirIdx});
                vis.insert({nextRow, nextCol, dirIdx});
            }
        }

        return res;
    }
};