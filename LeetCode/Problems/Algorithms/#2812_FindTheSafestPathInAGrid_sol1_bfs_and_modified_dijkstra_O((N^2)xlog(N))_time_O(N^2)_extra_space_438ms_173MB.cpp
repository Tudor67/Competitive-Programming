class Solution {
private:
    enum Cell { EMPTY = 0, THIEF = 1 };
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int INF = 1e9;
    
    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void computeThiefDist(vector<vector<int>>& grid, vector<vector<int>>& thiefDist){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        thiefDist.assign(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == Cell::THIEF){
                    q.push({row, col});
                    thiefDist[row][col] = 0;
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
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    if(thiefDist[row][col] + 1 < thiefDist[nextRow][nextCol]){
                        thiefDist[nextRow][nextCol] = thiefDist[row][col] + 1;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
    }

    int computeMaxSafeness(const pair<int, int>& SRC, const pair<int, int>& DEST,
                           vector<vector<int>>& thiefDist){
        const int ROWS = thiefDist.size();
        const int COLS = thiefDist[0].size();
        
        vector<vector<int>> maxSafeness(ROWS, vector<int>(COLS, -1));
        maxSafeness[SRC.first][SRC.second] = thiefDist[0][0];
        using State = tuple<int, int, int>;
        set<State> statesSet;
        statesSet.insert({maxSafeness[SRC.first][SRC.second], SRC.first, SRC.second});

        while(!statesSet.empty()){
            int row = get<1>(*statesSet.rbegin());
            int col = get<2>(*statesSet.rbegin());
            statesSet.erase(prev(statesSet.end()));

            if(row == DEST.first && col == DEST.second){
                return maxSafeness[row][col];
            }

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    int nextMaxSafeness = min(maxSafeness[row][col], thiefDist[nextRow][nextCol]);
                    if(maxSafeness[nextRow][nextCol] < nextMaxSafeness){
                        statesSet.erase({maxSafeness[nextRow][nextCol], nextRow, nextCol});
                        maxSafeness[nextRow][nextCol] = nextMaxSafeness;
                        statesSet.insert({maxSafeness[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        }
        
        return -1;
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        vector<vector<int>> thiefDist;
        computeThiefDist(grid, thiefDist);
        return computeMaxSafeness({0, 0}, {ROWS - 1, COLS - 1}, thiefDist);
    }
};