class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(int row, int col, vector<vector<int>>& fishCount, int& collectedFish){
        const int ROWS = fishCount.size();
        const int COLS = fishCount[0].size();

        if(!(0 <= row && row < ROWS && 0 <= col && col < COLS)){
            return;
        }

        if(fishCount[row][col] == 0){
            return;
        }

        collectedFish += fishCount[row][col];
        fishCount[row][col] = 0;

        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            dfs(nextRow, nextCol, fishCount, collectedFish);
        }
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int maxCollectedFish = 0;
        vector<vector<int>> fishCount = grid;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int collectedFish = 0;
                dfs(row, col, fishCount, collectedFish);
                maxCollectedFish = max(maxCollectedFish, collectedFish);
            }
        }

        return maxCollectedFish;
    }
};