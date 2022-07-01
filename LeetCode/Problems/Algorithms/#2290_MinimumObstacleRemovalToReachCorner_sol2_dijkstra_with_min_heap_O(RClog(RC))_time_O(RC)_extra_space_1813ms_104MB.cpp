class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        static const int INF = 1e8;
        
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        using State = tuple<int, int, int>;
        vector<vector<int>> minDist(ROWS, vector<int>(COLS, INF));
        priority_queue<State, vector<State>, greater<State>> minHeap;
        minDist[0][0] = 0;
        minHeap.emplace(minDist[0][0], 0, 0);
        
        while(!minHeap.empty()){
            int currentDist, row, col;
            tie(currentDist, row, col) = minHeap.top();
            minHeap.pop();
            
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
                        minHeap.emplace(minDist[nextRow][nextCol], nextRow, nextCol);
                    }
                }
            }
        }
        
        return minDist[ROWS - 1][COLS - 1];
    }
};