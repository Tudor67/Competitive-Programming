class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void dfs(int row, int col, vector<vector<int>>& grid, int& sum){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        if(row < 0 || ROWS <= row || col < 0 || COLS <= col || grid[row][col] == 0){
            return;
        }
        
        sum += grid[row][col];
        grid[row][col] = 0;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            dfs(nextRow, nextCol, grid, sum);
        }
    }
    
public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<int>> gridCopy = grid;
        
        int maxSum = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(gridCopy[row][col] > 0){
                    int sum = 0;
                    dfs(row, col, gridCopy, sum);
                    maxSum = max(maxSum, sum);
                }
            }
        }
        
        return maxSum;
    }
};