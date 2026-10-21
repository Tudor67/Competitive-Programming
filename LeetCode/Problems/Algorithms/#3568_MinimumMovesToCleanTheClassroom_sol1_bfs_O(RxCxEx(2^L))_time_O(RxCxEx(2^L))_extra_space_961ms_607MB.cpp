class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int INF = 1'000'000'000;

    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

public:
    int minMoves(vector<string>& grid, int energyCapacity) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int sRow = -1;
        int sCol = -1;
        int currLId = 0;
        vector<vector<int>> lId(ROWS, vector<int>(COLS, -1));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 'S'){
                    sRow = row;
                    sCol = col;
                }else if(grid[row][col] == 'L'){
                    lId[row][col] = currLId;
                    currLId += 1;
                }
            }
        }

        const int L = currLId;
        const int FULL_MASK = (1 << L) - 1;
        // minSteps[row][col][e][mask]: min moves to reach cell (row, col)
        //                              with e energy remaining
        //                              and all visited L cells being encoded in the 1 bits of mask
        // maxEnergy[row][col][mask]: max energy e seen for each (row, col, mask) state
        vector<vector<vector<vector<int>>>> minSteps(ROWS, vector<vector<vector<int>>>(COLS, vector<vector<int>>(energyCapacity + 1, vector<int>(FULL_MASK + 1, INF))));
        vector<vector<vector<int>>> maxEnergy(ROWS, vector<vector<int>>(COLS, vector<int>(FULL_MASK + 1, -1)));
        queue<array<int, 4>> q;
        
        minSteps[sRow][sCol][energyCapacity][0] = 0;
        maxEnergy[sRow][sCol][0] = energyCapacity;
        q.push({sRow, sCol, energyCapacity, 0});

        while(!q.empty()){
            auto [currRow, currCol, currE, currMask] = q.front();
            q.pop();

            if(currMask == FULL_MASK){
                return minSteps[currRow][currCol][currE][currMask];
            }

            if(currE == 0){
                continue;
            }

            for(const auto& [rowDir, colDir]: DIRECTIONS){
                int nextRow = currRow + rowDir;
                int nextCol = currCol + colDir;
                if(!isInside(nextRow, nextCol, ROWS, COLS) ||
                   grid[nextRow][nextCol] == 'X'){
                    continue;
                }

                int nextE = (grid[nextRow][nextCol] == 'R' ? energyCapacity : currE - 1);
                int nextMask = currMask | (grid[nextRow][nextCol] == 'L' ? (1 << lId[nextRow][nextCol]) : 0);

                // pruning step
                if(nextE <= maxEnergy[nextRow][nextCol][nextMask]){
                    continue;
                }

                if(minSteps[nextRow][nextCol][nextE][nextMask] > minSteps[currRow][currCol][currE][currMask] + 1){
                    minSteps[nextRow][nextCol][nextE][nextMask] = minSteps[currRow][currCol][currE][currMask] + 1;
                    maxEnergy[nextRow][nextCol][nextMask] = nextE;
                    q.push({nextRow, nextCol, nextE, nextMask});
                }
            }
        }

        return -1;
    }
};