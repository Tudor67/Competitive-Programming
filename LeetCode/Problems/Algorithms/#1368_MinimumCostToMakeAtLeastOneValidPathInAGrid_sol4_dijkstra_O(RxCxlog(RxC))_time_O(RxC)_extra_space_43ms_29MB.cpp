class Solution {
private:
    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> minCost(ROWS, vector<int>(COLS, INF));
        minCost[0][0] = 0;

        set<tuple<int, int, int>> statesSet;
        statesSet.insert({minCost[0][0], 0, 0});

        while(!statesSet.empty()){
            int row = get<1>(*statesSet.begin());
            int col = get<2>(*statesSet.begin());
            statesSet.erase(statesSet.begin());

            for(int i = 0; i < DIRECTIONS.size(); ++i){
                int nextRow = row + DIRECTIONS[i].first;
                int nextCol = col + DIRECTIONS[i].second;
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    int nextCost = minCost[row][col] + (int)(i + 1 != grid[row][col]);
                    if(minCost[nextRow][nextCol] > nextCost){
                        statesSet.erase({minCost[nextRow][nextCol], nextRow, nextCol});
                        minCost[nextRow][nextCol] = nextCost;
                        statesSet.insert({minCost[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        }

        return minCost[ROWS - 1][COLS - 1];
    }
};