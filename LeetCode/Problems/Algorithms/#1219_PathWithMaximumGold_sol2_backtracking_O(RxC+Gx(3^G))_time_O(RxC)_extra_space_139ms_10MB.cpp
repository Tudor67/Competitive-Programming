class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int getMaximumGold(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        if(!(0 <= row && row < ROWS && 0 <= col && col < COLS && grid[row][col] > 0)){
            return 0;
        }

        int initialGold = grid[row][col];
        int maxGold = 0;
        grid[row][col] = 0;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            maxGold = max(maxGold, initialGold + getMaximumGold(nextRow, nextCol, grid));
        }
        grid[row][col] = initialGold;

        return maxGold;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int maxGold = 0;
        vector<vector<int>> gridCopy = grid;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(gridCopy[row][col] > 0){
                    maxGold = max(maxGold, getMaximumGold(row, col, gridCopy));
                }
            }
        }

        return maxGold;
    }
};