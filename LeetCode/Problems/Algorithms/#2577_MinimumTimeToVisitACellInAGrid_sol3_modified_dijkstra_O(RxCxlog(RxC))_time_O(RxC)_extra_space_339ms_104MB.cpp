class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int INF = 1e9;

    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

public:
    int minimumTime(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

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

            bool isPossibleToMove = false;
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS) && minTime[row][col] + 1 >= grid[nextRow][nextCol]){
                    isPossibleToMove = true;
                }
            }

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    int nextMinTime = INF;
                    if(minTime[row][col] + 1 >= grid[nextRow][nextCol]){
                        nextMinTime = minTime[row][col] + 1;
                    }else if(isPossibleToMove){
                        nextMinTime = grid[nextRow][nextCol] + (grid[nextRow][nextCol] + 1 - minTime[row][col]) % 2;
                    }

                    if(minTime[nextRow][nextCol] > nextMinTime){
                        statesSet.erase({minTime[nextRow][nextCol], nextRow, nextCol});
                        minTime[nextRow][nextCol] = nextMinTime;
                        statesSet.insert({minTime[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        }

        return -1;
    }
};