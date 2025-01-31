class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void dfs(int row, int col, int ccId, vector<vector<int>>& ccIdOf, vector<pair<int, int>>& ccCells){
        const int ROWS = ccIdOf.size();
        const int COLS = ccIdOf[0].size();

        if(!isInside(row, col, ROWS, COLS) || ccIdOf[row][col] != 1){
            return;
        }

        ccIdOf[row][col] = ccId;
        ccCells.push_back({row, col});
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            dfs(row + DIRECTION.first, col + DIRECTION.second, ccId, ccIdOf, ccCells);
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int ccId = 1;
        vector<vector<int>> ccIdOf = grid;
        vector<vector<int>> ccSizeOf(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(ccIdOf[row][col] == 1){
                    ccId += 1;
                    vector<pair<int, int>> ccCells;
                    dfs(row, col, ccId, ccIdOf, ccCells);

                    int ccSize = ccCells.size();
                    for(const pair<int, int>& CELL: ccCells){
                        ccSizeOf[CELL.first][CELL.second] = ccSize;
                    }
                }
            }
        }

        int maxIslandSize = ccSizeOf[0][0];
        set<int> neighSet;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0){
                    int islandSize = 1;
                    neighSet.clear();
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int neighRow = row + DIRECTION.first;
                        int neighCol = col + DIRECTION.second;
                        if(isInside(neighRow, neighCol, ROWS, COLS) &&
                           !neighSet.count(ccIdOf[neighRow][neighCol])){
                            neighSet.insert(ccIdOf[neighRow][neighCol]);
                            islandSize += ccSizeOf[neighRow][neighCol];
                        }
                    }
                    maxIslandSize = max(maxIslandSize, islandSize);
                }
            }
        }

        return maxIslandSize;
    }
};