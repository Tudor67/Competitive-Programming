class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        static const int INF = 1e8;
        
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<int>> minDist(ROWS, vector<int>(COLS, INF));
        set<tuple<int, int, int>> states;
        minDist[0][0] = 0;
        states.emplace(minDist[0][0], 0, 0);
        
        while(!states.empty()){
            int row = get<1>(*states.begin());
            int col = get<2>(*states.begin());
            states.erase(states.begin());
            
            if(row == ROWS - 1 && col == COLS - 1){
                break;
            }
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int transitionCost = grid[nextRow][nextCol];
                    if(minDist[row][col] + transitionCost < minDist[nextRow][nextCol]){
                        states.erase({minDist[nextRow][nextCol], nextRow, nextCol});
                        minDist[nextRow][nextCol] = minDist[row][col] + transitionCost;
                        states.emplace(minDist[nextRow][nextCol], nextRow, nextCol);
                    }
                }
            }
        }
        
        return minDist[ROWS - 1][COLS - 1];
    }
};