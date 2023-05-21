class Solution {
private:
    const int INF = 1e9;
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(int row, int col, int islandID, vector<vector<int>>& islandIDOf){
        const int ROWS = islandIDOf.size();
        const int COLS = islandIDOf[0].size();

        islandIDOf[row][col] = islandID;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                if(islandIDOf[nextRow][nextCol] == 1){
                    dfs(nextRow, nextCol, islandID, islandIDOf);
                }
            }
        }
    }

    void bfs(vector<pair<int, int>>& srcCells, vector<vector<int>>& islandIDOf, vector<vector<int>>& dist){
        const int ROWS = islandIDOf.size();
        const int COLS = islandIDOf[0].size();

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                dist[row][col] = INF;
            }
        }

        queue<pair<int, int>> q;
        for(const pair<int, int>& CELL: srcCells){
            int row = CELL.first;
            int col = CELL.second;
            q.push({row, col});
            dist[row][col] = 0;
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(dist[row][col] + 1 < dist[nextRow][nextCol]){
                        dist[nextRow][nextCol] = dist[row][col] + 1;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        // Step 1: mark (with dfs) the cells of the second island (with value 2)
        int srcRow = 0;
        int srcCol = 0;
        vector<vector<int>> islandIDOf = grid;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(islandIDOf[row][col] == 1){
                    srcRow = row;
                    srcCol = col;
                }
            }
        }

        dfs(srcRow, srcCol, 2, islandIDOf);

        // Step 2: compute (with bfs) the min distance between cells of islands 1 and 2
        vector<pair<int, int>> srcCells;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(islandIDOf[row][col] == 1){
                    srcCells.push_back({row, col});
                }
            }
        }

        vector<vector<int>> dist(ROWS, vector<int>(COLS));
        bfs(srcCells, islandIDOf, dist);

        int res = INF;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(islandIDOf[row][col] == 2){
                    res = min(res, dist[row][col] - 1);
                }
            }
        }

        return res;
    }
};