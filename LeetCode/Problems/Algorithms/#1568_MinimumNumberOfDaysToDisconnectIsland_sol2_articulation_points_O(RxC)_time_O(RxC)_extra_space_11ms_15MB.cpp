class Solution {
private:
    using Graph = vector<vector<int>>;
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

    int cellToNode(int row, int col, const int COLS){
        return row * COLS + col;
    }

    void dfs(int parent, int node, int& currentTime, vector<int>& tin, vector<int>& low,
             bool& containsArticulationPoint, const Graph& G){
        currentTime += 1;
        tin[node] = currentTime;
        low[node] = currentTime;
        int childCount = 0;
        
        for(int nextNode: G[node]){
            if(nextNode == parent){
                // ignore this edge
            }else if(tin[nextNode] > 0){
                low[node] = min(low[node], tin[nextNode]);
            }else{
                dfs(node, nextNode, currentTime, tin, low, containsArticulationPoint, G);
                childCount += 1;
                if((parent == -1 && childCount >= 2) ||
                   (parent != -1 && tin[node] <= low[nextNode])){
                    containsArticulationPoint = true;
                }
                low[node] = min(low[node], low[nextNode]);
            }
        }
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
        //         this is the same as checking if
        //              * there is at least one articulation point
        //                in the graph formed by the input grid
        //                or
        //              * the total number of land cells is 1
        const int N = ROWS * COLS;
        Graph G(N);
        int root = -1;
        int totalLandCells = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == CellType::LAND){
                    totalLandCells += 1;
                    root = cellToNode(row, col, COLS);
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int neighRow = row + DIRECTION.first;
                        int neighCol = col + DIRECTION.second;
                        if(isInside(neighRow, neighCol, grid) && grid[neighRow][neighCol] == CellType::LAND){
                            G[cellToNode(row, col, COLS)].push_back(cellToNode(neighRow, neighCol, COLS));
                        }
                    }
                }
            }
        }

        int currentTime = 0;
        vector<int> tin(N);
        vector<int> low(N);
        bool containsArticulationPoint = false;
        dfs(-1, root, currentTime, tin, low, containsArticulationPoint, G);

        if(containsArticulationPoint || totalLandCells == 1){
            return 1;
        }

        // Case 2: disconnect any land cell located at the corner of the island
        //         by removing 2 land neighbors ==> return 2
        return 2;
    }
};