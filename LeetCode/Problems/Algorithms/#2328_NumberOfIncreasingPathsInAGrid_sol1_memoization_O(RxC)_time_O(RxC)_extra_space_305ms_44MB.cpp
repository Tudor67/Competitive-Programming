class Solution {
private:
    const int MODULO = 1e9 + 7;
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isInside(int row, int col, const int& ROWS, const int& COLS){
        return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
    }

    int computeTotalPaths(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& memo){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        if(memo[row][col] >= 0){
            return memo[row][col];
        }

        int totalPaths = 1;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(isInside(nextRow, nextCol, ROWS, COLS) && grid[row][col] > grid[nextRow][nextCol]){
                totalPaths += computeTotalPaths(nextRow, nextCol, grid, memo);
                totalPaths %= MODULO;
            }
        }

        memo[row][col] = totalPaths;
        return totalPaths;
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int res = 0;
        vector<vector<int>> memo(ROWS, vector<int>(COLS, -1));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res += computeTotalPaths(row, col, grid, memo);
                res %= MODULO;
            }
        }

        return res;
    }
};