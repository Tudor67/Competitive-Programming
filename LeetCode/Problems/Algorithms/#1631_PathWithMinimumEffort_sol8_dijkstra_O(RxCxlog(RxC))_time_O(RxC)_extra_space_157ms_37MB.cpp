class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        vector<vector<int>> minCost(ROWS, vector<int>(COLS, INF));
        minCost[0][0] = 0;

        using State = tuple<int, int, int>;
        set<State> statesSet;
        statesSet.insert({minCost[0][0], 0, 0});

        while(!statesSet.empty()){
            int row = get<1>(*statesSet.begin());
            int col = get<2>(*statesSet.begin());
            statesSet.erase(statesSet.begin());

            if(row == ROWS - 1 && col == COLS - 1){
                break;
            }

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int nextCost = max(minCost[row][col], abs(heights[row][col] - heights[nextRow][nextCol]));
                    if(nextCost < minCost[nextRow][nextCol]){
                        statesSet.erase({minCost[nextRow][nextCol], nextRow, nextCol});
                        minCost[nextRow][nextCol] = nextCost;
                        statesSet.insert({minCost[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        }
        
        return minCost[ROWS - 1][COLS - 1];
    }
};