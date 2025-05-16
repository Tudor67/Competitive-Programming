class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int ROWS = moveTime.size();
        const int COLS = moveTime[0].size();
        const int INF = 2e9;
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        // minTime[0][row][col]: min time to reach (row, col) in even number of steps
        // minTime[1][row][col]: min time to reach (row, col) in odd number of steps
        vector<vector<vector<int>>> minTime(2, vector<vector<int>>(ROWS, vector<int>(COLS, INF)));
        minTime[0][0][0] = 0;

        using State = array<int, 4>;
        set<State> statesSet;
        statesSet.insert({minTime[0][0][0], 0, 0, 0});

        while(!statesSet.empty()){
            int stepsParity = (*statesSet.begin())[1];
            int row = (*statesSet.begin())[2];
            int col = (*statesSet.begin())[3];
            statesSet.erase(statesSet.begin());

            for(auto& [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int transitionCost = stepsParity + 1;
                    int nextMinTime = max(minTime[stepsParity][row][col], moveTime[nextRow][nextCol]) + transitionCost;
                    if(minTime[(stepsParity + 1) % 2][nextRow][nextCol] > nextMinTime){
                        statesSet.erase({minTime[(stepsParity + 1) % 2][nextRow][nextCol], (stepsParity + 1) % 2, nextRow, nextCol});
                        minTime[(stepsParity + 1) % 2][nextRow][nextCol] = nextMinTime;
                        statesSet.insert({minTime[(stepsParity + 1) % 2][nextRow][nextCol], (stepsParity + 1) % 2, nextRow, nextCol});
                    }
                }
            }
        }

        return min(minTime[0][ROWS - 1][COLS - 1], minTime[1][ROWS - 1][COLS - 1]);
    }
};