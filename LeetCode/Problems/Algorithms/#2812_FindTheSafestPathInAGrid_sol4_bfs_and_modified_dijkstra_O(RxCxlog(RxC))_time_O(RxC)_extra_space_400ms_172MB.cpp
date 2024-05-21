class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int INF = 1e9;

    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void computeSafeness(vector<vector<int>>& grid, vector<vector<int>>& safeness){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col]){
                    safeness[row][col] = 0;
                    q.push({row, col});
                }else{
                    safeness[row][col] = INF;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS) && safeness[nextRow][nextCol] == INF){
                    safeness[nextRow][nextCol] = safeness[row][col] + 1;
                    q.push({nextRow, nextCol});
                }
            }
        }
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        // Step 1: compute safeness factor of each cell
        vector<vector<int>> safeness(ROWS, vector<int>(COLS));
        computeSafeness(grid, safeness);

        // Step 2: find the max safeness factor of all paths from (0, 0) to (ROWS - 1, COLS - 1)
        //         with modified Dijkstra's algorithm
        vector<vector<int>> maxValidSafeness(ROWS, vector<int>(COLS, INF));
        set<pair<int, pair<int, int>>> statesSet;
        maxValidSafeness[0][0] = safeness[0][0];
        statesSet.insert({maxValidSafeness[0][0], {0, 0}});

        while(!statesSet.empty() && maxValidSafeness[ROWS - 1][COLS - 1] == INF){
            int row = statesSet.rbegin()->second.first;
            int col = statesSet.rbegin()->second.second;
            statesSet.erase(prev(statesSet.end()));

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS) && maxValidSafeness[nextRow][nextCol] == INF){
                    statesSet.erase({maxValidSafeness[nextRow][nextCol], {nextRow, nextCol}});
                    maxValidSafeness[nextRow][nextCol] = min(maxValidSafeness[row][col], safeness[nextRow][nextCol]);
                    statesSet.insert({maxValidSafeness[nextRow][nextCol], {nextRow, nextCol}});
                }
            }
        }

        return maxValidSafeness[ROWS - 1][COLS - 1];
    }
};