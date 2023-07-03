class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int INF = 1e9;
        const char STARTING_POINT = '@';
        const char WALL = '#';

        int startRow = 0;
        int startCol = 0;
        int totalKeys = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == STARTING_POINT){
                    startRow = row;
                    startCol = col;
                }else if(islower(grid[row][col])){
                    totalKeys = max(totalKeys, grid[row][col] - 'a' + 1);
                }
            }
        }

        // State: (row, col, keysMask)
        using State = tuple<int, int, int>;
        vector<vector<vector<int>>> minDist(ROWS, vector<vector<int>>(COLS, vector<int>(1 << totalKeys, INF)));
        queue<State> q;
        minDist[startRow][startCol][0] = 0;
        q.push({startRow, startCol, 0});

        while(!q.empty()){
            State state = q.front();
            q.pop();

            int row, col, keysMask;
            tie(row, col, keysMask) = state;

            if(__builtin_popcount(keysMask) == totalKeys){
                return minDist[row][col][keysMask];
            }

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && grid[nextRow][nextCol] != WALL){
                    int nextKeysMask = keysMask;
                    if(islower(grid[nextRow][nextCol])){
                        nextKeysMask |= (1 << (grid[nextRow][nextCol] - 'a'));
                    }

                    if(minDist[row][col][keysMask] + 1 < minDist[nextRow][nextCol][nextKeysMask]){
                        if(!isupper(grid[nextRow][nextCol]) || ((keysMask >> (grid[nextRow][nextCol] - 'A')) & 1)){
                            minDist[nextRow][nextCol][nextKeysMask] = minDist[row][col][keysMask] + 1;
                            q.push({nextRow, nextCol, nextKeysMask});
                        }
                    }
                }
            }
        }

        return -1;
    }
};