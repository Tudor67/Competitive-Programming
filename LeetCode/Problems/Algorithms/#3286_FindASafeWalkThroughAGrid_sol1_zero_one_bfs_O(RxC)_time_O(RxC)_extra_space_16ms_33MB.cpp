class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int INF = 1e9;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> minCost(ROWS, vector<int>(COLS, INF));
        deque<pair<int, int>> dq;

        minCost[0][0] = grid[0][0];
        dq.push_back({0, 0});

        while(!dq.empty()){
            auto [row, col] = dq.front();
            dq.pop_front();

            for(const auto& [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int nextMinCost = minCost[row][col] + grid[nextRow][nextCol];
                    if(minCost[nextRow][nextCol] > nextMinCost){
                        minCost[nextRow][nextCol] = nextMinCost;
                        if(grid[nextRow][nextCol] == 0){
                            dq.push_front({nextRow, nextCol});
                        }else{
                            dq.push_back({nextRow, nextCol});
                        }
                    }
                }
            }
        }

        return (minCost[ROWS - 1][COLS - 1] < health);
    }
};