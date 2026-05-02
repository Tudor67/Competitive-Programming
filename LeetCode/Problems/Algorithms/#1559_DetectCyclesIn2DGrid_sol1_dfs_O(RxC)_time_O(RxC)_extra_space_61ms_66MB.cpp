class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    bool isInside(int row, int col, vector<vector<char>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void dfs(int row, int col, int depth, char targetColor, vector<vector<char>>& grid, vector<vector<int>>& depthOf){
        if(!isInside(row, col, grid) ||
           grid[row][col] != targetColor ||
           depthOf[row][col] >= 1){
            return;
        }
        
        depthOf[row][col] = depth;
        for(const auto& [rowDir, colDir]: DIRECTIONS){
            dfs(row + rowDir, col + colDir, depth + 1, targetColor, grid, depthOf);
        }
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> depthOf(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                dfs(row, col, 1, grid[row][col], grid, depthOf);
            }
        }

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(const auto& [rowDir, colDir]: DIRECTIONS){
                    int nextRow = row + rowDir;
                    int nextCol = col + colDir;
                    if(isInside(nextRow, nextCol, grid) &&
                        grid[nextRow][nextCol] == grid[row][col] &&
                        abs(depthOf[nextRow][nextCol] - depthOf[row][col]) >= 3){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};