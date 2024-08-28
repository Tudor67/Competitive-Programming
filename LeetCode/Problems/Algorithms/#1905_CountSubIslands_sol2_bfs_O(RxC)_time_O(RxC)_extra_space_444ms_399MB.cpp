class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    bool isInside(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void bfs(int srcRow, int srcCol, vector<vector<int>>& grid, int ccID,
             vector<vector<int>>& cc, vector<pair<int, int>>& coordinates){
        queue<pair<int, int>> q;
        if(grid[srcRow][srcCol] == 1 && cc[srcRow][srcCol] == 0){
            cc[srcRow][srcCol] = ccID;
            q.push({srcRow, srcCol});
        }
        coordinates.clear();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            coordinates.push_back({row, col});

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, grid) && grid[nextRow][nextCol] == 1 && cc[nextRow][nextCol] == 0){
                    cc[nextRow][nextCol] = ccID;
                    q.push({nextRow, nextCol});
                }
            }
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int ROWS = grid1.size();
        const int COLS = grid1[0].size();

        int ccID = 0;
        vector<pair<int, int>> coordinates;
        vector<vector<int>> cc1(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid1[row][col] == 1 && cc1[row][col] == 0){
                    ccID += 1;
                    bfs(row, col, grid1, ccID, cc1, coordinates);
                }
            }
        }

        int subIslands = 0;
        ccID = 0;
        vector<vector<int>> cc2(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid2[row][col] == 1 && cc2[row][col] == 0){
                    ccID += 1;
                    bfs(row, col, grid2, ccID, cc2, coordinates);

                    int targetCC1ID = cc1[coordinates[0].first][coordinates[0].second];
                    bool isSubIsland = (targetCC1ID != 0);
                    for(int i = 0; i < (int)coordinates.size() && isSubIsland; ++i){
                        if(cc1[coordinates[i].first][coordinates[i].second] != targetCC1ID){
                            isSubIsland = false;
                        }
                    }

                    if(isSubIsland){
                        subIslands += 1;
                    }
                }
            }
        }

        return subIslands;
    }
};