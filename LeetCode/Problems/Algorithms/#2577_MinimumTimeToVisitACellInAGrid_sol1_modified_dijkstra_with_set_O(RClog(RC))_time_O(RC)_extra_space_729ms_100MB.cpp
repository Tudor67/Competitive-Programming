class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        if(grid[0][1] >= 2 && grid[1][0] >= 2){
            return -1;
        }

        vector<vector<int>> minTime(ROWS, vector<int>(COLS, INF));
        set<tuple<int, int, int>> statesSet;
        minTime[0][0] = 0;
        statesSet.insert({minTime[0][0], 0, 0});

        while(!statesSet.empty()){
            int row = get<1>(*statesSet.begin());
            int col = get<2>(*statesSet.begin());
            statesSet.erase(statesSet.begin());

            if(row == ROWS - 1 && col == COLS - 1){
                return minTime[row][col];
            }

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int nextValidTime = minTime[row][col] + 1;
                    if(nextValidTime < grid[nextRow][nextCol]){
                        if(nextValidTime % 2 == grid[nextRow][nextCol] % 2){
                            nextValidTime = grid[nextRow][nextCol];
                        }else{
                            nextValidTime = grid[nextRow][nextCol] + 1;
                        }
                    }

                    if(nextValidTime < minTime[nextRow][nextCol]){
                        statesSet.erase({minTime[nextRow][nextCol], nextRow, nextCol});
                        minTime[nextRow][nextCol] = nextValidTime;
                        statesSet.insert({minTime[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        }

        return -1;
    }
};