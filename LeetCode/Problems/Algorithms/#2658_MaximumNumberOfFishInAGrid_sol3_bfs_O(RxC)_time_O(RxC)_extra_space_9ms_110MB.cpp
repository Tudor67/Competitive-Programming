class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int bfs(int srcRow, int srcCol, vector<vector<int>>& fishCount){
        const int ROWS = fishCount.size();
        const int COLS = fishCount[0].size();

        if(fishCount[srcRow][srcCol] == 0){
            return 0;
        }

        int collectedFish = fishCount[srcRow][srcCol];
        fishCount[srcRow][srcCol] = 0;
        
        queue<pair<int, int>> q;
        q.push({srcRow, srcCol});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(fishCount[nextRow][nextCol] > 0){
                        collectedFish += fishCount[nextRow][nextCol];
                        fishCount[nextRow][nextCol] = 0;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }

        return collectedFish;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int maxCollectedFish = 0;
        vector<vector<int>> fishCount = grid;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int collectedFish = bfs(row, col, fishCount);
                maxCollectedFish = max(maxCollectedFish, collectedFish);
            }
        }

        return maxCollectedFish;
    }
};