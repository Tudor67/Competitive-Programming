class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        enum CellType { EMPTY = 0, OBSTACLE = 1 };

        vector<vector<int>> minCost(ROWS, vector<int>(COLS, INF));
        deque<tuple<int, int, int>> statesDQ;
        minCost[0][0] = 0;
        statesDQ.push_front({minCost[0][0], 0, 0});

        while(!statesDQ.empty()){
            int row = get<1>(statesDQ.front());
            int col = get<2>(statesDQ.front());
            statesDQ.pop_front();

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int nextCost = minCost[row][col] + (int)(grid[nextRow][nextCol] == CellType::OBSTACLE);
                    if(minCost[nextRow][nextCol] > nextCost){
                        minCost[nextRow][nextCol] = nextCost;
                        if(minCost[row][col] == minCost[nextRow][nextCol]){
                            statesDQ.push_front({minCost[nextRow][nextCol], nextRow, nextCol});
                        }else{
                            statesDQ.push_back({minCost[nextRow][nextCol], nextRow, nextCol});
                        }
                    }
                }
            }
        }
        
        return minCost[ROWS - 1][COLS - 1];
    }
};