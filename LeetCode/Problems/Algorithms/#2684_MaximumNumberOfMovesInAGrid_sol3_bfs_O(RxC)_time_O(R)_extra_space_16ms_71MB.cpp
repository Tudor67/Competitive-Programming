class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            q.push({row, 0});
        }

        int maxVisitedCol = -1;
        vector<bool> vis(ROWS);
        while(!q.empty()){
            maxVisitedCol += 1;
            fill(vis.begin(), vis.end(), false);

            for(int i = q.size(); i >= 1; --i){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                int nextCol = col + 1;
                for(int nextRow = row - 1; nextRow <= row + 1; ++nextRow){
                    if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                       !vis[nextRow] && grid[row][col] < grid[nextRow][nextCol]){
                        vis[nextRow] = true;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }

        return maxVisitedCol;
    }
};