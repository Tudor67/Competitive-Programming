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
        //         with modified Dijkstra's algorithm in a binary weight graph (0-1 BFS)
        vector<vector<int>> maxValidSafeness(ROWS, vector<int>(COLS, INF));
        deque<pair<int, pair<int, int>>> statesDQ;
        maxValidSafeness[0][0] = safeness[0][0];
        statesDQ.push_front({maxValidSafeness[0][0], {0, 0}});

        while(!statesDQ.empty() && maxValidSafeness[ROWS - 1][COLS - 1] == INF){
            int row = statesDQ.back().second.first;
            int col = statesDQ.back().second.second;
            statesDQ.pop_back();

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS) && maxValidSafeness[nextRow][nextCol] == INF){
                    maxValidSafeness[nextRow][nextCol] = min(maxValidSafeness[row][col], safeness[nextRow][nextCol]);
                    if(maxValidSafeness[row][col] > maxValidSafeness[nextRow][nextCol]){
                        statesDQ.push_front({maxValidSafeness[nextRow][nextCol], {nextRow, nextCol}});
                    }else{
                        statesDQ.push_back({maxValidSafeness[nextRow][nextCol], {nextRow, nextCol}});
                    }
                }
            }
        }

        return maxValidSafeness[ROWS - 1][COLS - 1];
    }
};