class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void bfs(int srcRow, int srcCol, vector<vector<int>>& grid1, vector<vector<int>>& grid2,
             vector<vector<bool>>& vis2, bool& isSubIsland){
        const int ROWS = grid2.size();
        const int COLS = grid2[0].size();

        queue<pair<int, int>> q;
        if(grid2[srcRow][srcCol] == 1 && !vis2[srcRow][srcCol]){
            vis2[srcRow][srcCol] = true;
            q.push({srcRow, srcCol});
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(grid1[row][col] == 0){
                isSubIsland = false;
            }

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   grid2[nextRow][nextCol] == 1 && !vis2[nextRow][nextCol]){
                    vis2[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol});
                }
            }
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int ROWS = grid1.size();
        const int COLS = grid1[0].size();

        int subIslands = 0;
        vector<vector<bool>> vis2(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid2[row][col] == 1 && !vis2[row][col]){
                    bool isSubIsland = true;
                    bfs(row, col, grid1, grid2, vis2, isSubIsland);
                    subIslands += (int)isSubIsland;
                }
            }
        }

        return subIslands;
    }
};