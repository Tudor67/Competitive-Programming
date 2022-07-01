class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        static const int INF = 1e8;
        
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<int>> minDist(ROWS, vector<int>(COLS, INF));
        deque<tuple<int, int, int>> dq;
        minDist[0][0] = 0;
        dq.emplace_back(minDist[0][0], 0, 0);
        
        while(!dq.empty()){
            int currentDist, row, col;
            tie(currentDist, row, col) = dq.front();
            dq.pop_front();
            
            if(row == ROWS - 1 && col == COLS - 1){
                break;
            }
            
            if(currentDist > minDist[row][col]){
                continue;
            }
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int transitionCost = grid[nextRow][nextCol];
                    if(minDist[row][col] + transitionCost < minDist[nextRow][nextCol]){
                        minDist[nextRow][nextCol] = minDist[row][col] + transitionCost;
                        if(transitionCost == 0){
                            dq.emplace_front(minDist[nextRow][nextCol], nextRow, nextCol);
                        }else{
                            dq.emplace_back(minDist[nextRow][nextCol], nextRow, nextCol);
                        }
                    }
                }
            }
        }
        
        return minDist[ROWS - 1][COLS - 1];
    }
};