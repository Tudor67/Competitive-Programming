class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        enum CellType { EMPTY, THIEF };
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        auto isInside = [&](int row, int col) -> bool {
            return (0 <= row && row < ROWS && 0 <= col && col < COLS);
        };

        queue<pair<int, int>> q;
        vector<vector<int>> safeness(ROWS, vector<int>(COLS, INF));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == CellType::THIEF){
                    safeness[row][col] = 0;
                    q.push({row, col});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(const auto& [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(isInside(nextRow, nextCol) && safeness[nextRow][nextCol] == INF){
                    safeness[nextRow][nextCol] = 1 + safeness[row][col];
                    q.push({nextRow, nextCol});
                }
            }
        }

        vector<vector<int>> maxSafeness(ROWS, vector<int>(COLS, 0));
        set<array<int, 3>> statesSet;
        maxSafeness[0][0] = safeness[0][0];
        statesSet.insert({maxSafeness[0][0], 0, 0});
        
        while(!statesSet.empty()){
            int row = (*prev(statesSet.end()))[1];
            int col = (*prev(statesSet.end()))[2];
            statesSet.erase(prev(statesSet.end()));

            for(const auto& [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(isInside(nextRow, nextCol)){
                    int nextMaxSafeness = min(maxSafeness[row][col], safeness[nextRow][nextCol]);
                    if(maxSafeness[nextRow][nextCol] < nextMaxSafeness){
                        statesSet.erase({maxSafeness[nextRow][nextCol], nextRow, nextCol});
                        maxSafeness[nextRow][nextCol] = nextMaxSafeness;
                        statesSet.insert({maxSafeness[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        }

        return maxSafeness[ROWS - 1][COLS - 1];
    }
};