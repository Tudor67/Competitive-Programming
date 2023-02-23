class Solution {
private:
    bool dfs(int row, int col, vector<vector<int>>& currentGrid){
        const int ROWS = currentGrid.size();
        const int COLS = currentGrid[0].size();

        if(row >= ROWS || col >= COLS || currentGrid[row][col] == 0){
            return false;
        }

        if(row == ROWS - 1 && col == COLS - 1){
            return true;
        }

        if(row != 0 || col != 0){
            currentGrid[row][col] = 0;
        }

        return dfs(row + 1, col, currentGrid) || dfs(row, col + 1, currentGrid);
    }

public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        // if we can find at least two non-intersecting valid paths from {0, 0} to {ROWS - 1, COLS - 1}
        // then we cannot make the matrix disconnected => return false;
        // otherwise => return true;
        vector<vector<int>> currentGrid = grid;
        bool found1 = dfs(0, 0, currentGrid);
        bool found2 = dfs(0, 0, currentGrid);

        return !(found1 && found2);
    }
};