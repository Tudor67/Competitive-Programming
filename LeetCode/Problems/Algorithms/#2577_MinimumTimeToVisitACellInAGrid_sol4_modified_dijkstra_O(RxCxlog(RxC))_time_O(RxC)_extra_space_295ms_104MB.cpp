class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int INF = 1e9;

public:
    int minimumTime(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        if(grid[0][1] >= 2 && grid[1][0] >= 2){
            return -1;
        }

        vector<vector<int>> minTime(ROWS, vector<int>(COLS, INF));
        set<tuple<int, int, int>> statesSet;
        minTime[0][0] = 0;
        statesSet.insert({minTime[0][0], 0, 0});

        while(!statesSet.empty() && minTime[ROWS - 1][COLS - 1] == INF){
            int row = get<1>(*statesSet.begin());
            int col = get<2>(*statesSet.begin());
            statesSet.erase(statesSet.begin());

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int nextMinTime = minTime[row][col] + 1;
                    if(nextMinTime < grid[nextRow][nextCol]){
                        nextMinTime = grid[nextRow][nextCol] +
                                      (grid[nextRow][nextCol] + 1 - minTime[row][col]) % 2;
                    }

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