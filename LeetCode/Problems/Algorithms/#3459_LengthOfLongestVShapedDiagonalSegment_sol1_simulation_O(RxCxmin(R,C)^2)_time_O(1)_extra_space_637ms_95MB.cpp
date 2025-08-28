class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

    bool isInside(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    int computeMaxDiagLen(vector<vector<int>>& grid, int row, int col, pair<int, int> dir, int targetVal){
        int maxDiagLen = 0;
        while(isInside(row, col, grid) && grid[row][col] == targetVal){
            maxDiagLen += 1;
            targetVal = 2 - targetVal;
            row += dir.first;
            col += dir.second;
        }
        return maxDiagLen;
    }

    int computeMaxVLen(vector<vector<int>>& grid, int startRow, int startCol){
        if(grid[startRow][startCol] != 1){
            return 0;
        }

        int maxVLen = 1;
        for(int dirIdx = 0; dirIdx < (int)DIRECTIONS.size(); ++dirIdx){
            pair<int, int> currDir = DIRECTIONS[dirIdx];
            pair<int, int> nextDir = DIRECTIONS[(dirIdx + 1) % DIRECTIONS.size()];
            int vLen = 1;
            int targetVal = 2;
            int row = startRow + currDir.first;
            int col = startCol + currDir.second;
            while(isInside(row, col, grid) && grid[row][col] == targetVal){
                maxVLen = max(maxVLen, vLen + computeMaxDiagLen(grid, row, col, nextDir, targetVal));
                vLen += 1;
                targetVal = 2 - targetVal;
                row += currDir.first;
                col += currDir.second;
            }
        }

        return maxVLen;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int maxLen = 0;
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                maxLen = max(maxLen, computeMaxVLen(grid, startRow, startCol));
            }
        }

        return maxLen;
    }
};