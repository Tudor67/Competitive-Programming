class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int ROWS = moveTime.size();
        const int COLS = moveTime[0].size();
        const int INF = 2e9;
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> minTime(ROWS, vector<int>(COLS, INF));
        using State = array<int, 3>;
        set<State> statesSet;
        minTime[0][0] = 0;
        statesSet.insert({minTime[0][0], 0, 0});

        while(!statesSet.empty()){
            int row = (*statesSet.begin())[1];
            int col = (*statesSet.begin())[2];
            statesSet.erase(statesSet.begin());

            for(auto& [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int nextMinTime = max(minTime[row][col] + 1, moveTime[nextRow][nextCol] + 1);
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