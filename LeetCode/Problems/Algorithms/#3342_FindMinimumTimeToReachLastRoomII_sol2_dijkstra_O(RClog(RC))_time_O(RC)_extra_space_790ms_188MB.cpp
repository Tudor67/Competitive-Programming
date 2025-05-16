class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int ROWS = moveTime.size();
        const int COLS = moveTime[0].size();
        const int INF = 2e9;
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        // minTime[row][col]: min time to reach (row, col)
        vector<vector<int>> minTime(ROWS, vector<int>(COLS, INF));
        minTime[0][0] = 0;

        using State = array<int, 3>;
        set<State> statesSet;
        statesSet.insert({minTime[0][0], 0, 0});

        while(!statesSet.empty()){
            int row = (*statesSet.begin())[1];
            int col = (*statesSet.begin())[2];
            statesSet.erase(statesSet.begin());

            for(auto& [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int transitionCost = 1 + (row + col) % 2;
                    int nextMinTime = max(minTime[row][col], moveTime[nextRow][nextCol]) + transitionCost;
                    if(minTime[nextRow][nextCol] > nextMinTime){
                        statesSet.erase({minTime[nextRow][nextCol], nextRow, nextCol});
                        minTime[nextRow][nextCol] = nextMinTime;
                        statesSet.insert({minTime[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        }

        return minTime[ROWS - 1][COLS - 1];
    }
};