class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        const int INF = 1e8;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        using CostRowCol = tuple<int, int, int>;
        vector<vector<int>> minCostAt(ROWS, vector<int>(COLS, INF));
        set<CostRowCol> states;
        minCostAt[0][0] = 0;
        states.emplace(minCostAt[0][0], 0, 0);
        
        while(!states.empty()){
            int cost, row, col;
            tie(cost, row, col) = *states.begin();
            states.erase(states.begin());
            
            if(row == ROWS - 1 && col == COLS - 1){
                return cost;
            }
            
            for(int dirIdx = 0; dirIdx < (int)DIRECTIONS.size(); ++dirIdx){
                int nextRow = row + DIRECTIONS[dirIdx].first;
                int nextCol = col + DIRECTIONS[dirIdx].second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int changeCost = (dirIdx != grid[row][col] - 1);
                    if(minCostAt[row][col] + changeCost < minCostAt[nextRow][nextCol]){
                        states.erase({minCostAt[nextRow][nextCol], nextRow, nextCol});
                        minCostAt[nextRow][nextCol] = minCostAt[row][col] + changeCost;
                        states.emplace(minCostAt[nextRow][nextCol], nextRow, nextCol);
                    }
                }
            }
        }
        
        return -1;
    }
};