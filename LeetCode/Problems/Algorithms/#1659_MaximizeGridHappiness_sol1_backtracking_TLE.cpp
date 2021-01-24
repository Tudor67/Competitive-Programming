class Solution {
private:
    int countNeighborsEqualTo(const int& VAL, int row, int col, vector<vector<int>>& grid){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int neighbors = 0;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            neighbors += (grid[nextRow][nextCol] == VAL);
        }
        return neighbors;
    }
    
    int happinessContrib(int row, int col, vector<vector<int>>& grid){
        int contrib = 0;
        int neigh1 = countNeighborsEqualTo(1, row, col, grid);
        int neigh2 = countNeighborsEqualTo(2, row, col, grid);
        if(grid[row][col] == 1){
            contrib = 120 - 30 * (neigh1 + neigh2) - 30 * neigh1 + 20 * neigh2;
        }else if(grid[row][col] == 2){
            contrib = 40 + 20 * (neigh1 + neigh2) - 30 * neigh1 + 20 * neigh2;
        }
        return contrib;
    }
    
    void back(int row, int col, int gridHappiness, vector<vector<int>>& grid, const int& ROWS, const int& COLS,
              int introvertsCount, int extrovertsCount, int& answer){
        answer = max(gridHappiness, answer);
        if(gridHappiness + 120 * (introvertsCount + extrovertsCount) <= answer){
            // Pruning: we cannot improve the answer => doesn't make sense to continue
        }else if(row <= ROWS){
            int nextRow = row;
            int nextCol = col + 1;
            if(nextCol == COLS + 1){
                nextRow = row + 1;
                nextCol = 1;
            }
            if(introvertsCount >= 1){
                grid[row][col] = 1;
                int nextGridHappiness = gridHappiness + happinessContrib(row, col, grid);
                back(nextRow, nextCol, nextGridHappiness, grid, ROWS, COLS, introvertsCount - 1, extrovertsCount, answer);
            }
            if(extrovertsCount >= 1){
                grid[row][col] = 2;
                int nextGridHappiness = gridHappiness + happinessContrib(row, col, grid);
                back(nextRow, nextCol, nextGridHappiness, grid, ROWS, COLS, introvertsCount, extrovertsCount - 1, answer);
            }
            grid[row][col] = 0;
            back(nextRow, nextCol, gridHappiness, grid, ROWS, COLS, introvertsCount, extrovertsCount, answer);
        }
    }
    
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        vector<vector<int>> grid(m + 2, vector<int>(n + 2, 0));
        int answer = 0;
        back(1, 1, 0, grid, m, n, introvertsCount, extrovertsCount, answer);
        return answer;
    }
};