class Solution {
private:
    enum CellType { WATER = 0, LAND = 1 };
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool isInside(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void floodFill(int row, int col, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        if(!isInside(row, col, grid) || vis[row][col] || grid[row][col] == CellType::WATER){
            return;
        }

        vis[row][col] = true;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            floodFill(row + DIRECTION.first, col + DIRECTION.second, vis, grid);
        }
    }

    bool isDisconnected(vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int islands = 0;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == CellType::LAND && !vis[row][col]){
                    islands += 1;
                    floodFill(row, col, vis, grid);
                }
            }
        }

        return (islands == 0 || islands >= 2);
    }

public:
    int minDays(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        // Case 0: initial grid is disconnected ==> return 0
        if(isDisconnected(grid)){
            return 0;
        }

        // Case 1: check if it is possible to disconnect the grid in one day
        //         by removing one land cell ==> return 1
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == CellType::LAND){
                    grid[row][col] = CellType::WATER;
                    bool isDisconnectedCheck = isDisconnected(grid);
                    grid[row][col] = CellType::LAND;
                    if(isDisconnectedCheck){
                        return 1;
                    }
                }
            }
        }

        // Case 2: disconnect any land cell located at the corner of the island
        //         by removing 2 land neighbors ==> return 2
        return 2;
    }
};