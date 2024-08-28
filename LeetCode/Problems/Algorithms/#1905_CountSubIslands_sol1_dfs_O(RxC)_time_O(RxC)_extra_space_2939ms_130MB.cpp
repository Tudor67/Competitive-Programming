class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    bool isInside(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void dfs(int row, int col, vector<vector<int>>& grid, int ccID,
             vector<vector<int>>& cc, vector<pair<int, int>>& coordinates){
        if(!isInside(row, col, grid) || grid[row][col] == 0 || cc[row][col] != 0){
            return;
        }
        cc[row][col] = ccID;
        coordinates.push_back({row, col});
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            dfs(row + DIRECTION.first, col + DIRECTION.second, grid, ccID, cc, coordinates);
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
                    coordinates.clear();
                    dfs(row, col, grid1, ccID, cc1, coordinates);
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
                    coordinates.clear();
                    dfs(row, col, grid2, ccID, cc2, coordinates);

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