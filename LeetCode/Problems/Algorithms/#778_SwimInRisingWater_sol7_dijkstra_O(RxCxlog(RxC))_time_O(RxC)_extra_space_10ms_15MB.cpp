class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int INF = 1e9;

        using State = array<int, 3>;
        set<State> statesSet;
        vector<vector<int>> minTime(ROWS, vector<int>(COLS, INF));

        minTime[0][0] = grid[0][0];
        statesSet.insert({minTime[0][0], 0, 0});

        while(!statesSet.empty()){
            int row = (*statesSet.begin())[1];
            int col = (*statesSet.begin())[2];
            statesSet.erase(statesSet.begin());

            for(const auto& [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int nextMinTime = max(minTime[row][col], grid[nextRow][nextCol]);
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