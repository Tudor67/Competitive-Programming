class Solution {
private:
    const int INF = 1e9;

    int abs(int x){
        return max(x, -x);
    }

    int solve(int i, int mask, vector<pair<int, int>>& emptyCells, vector<pair<int, int>>& extraCells, vector<int>& memo){
        const int M = emptyCells.size();

        if(i == M){
            return 0;
        }

        if(memo[mask] != INF){
            return memo[mask];
        }

        int res = INF;
        for(int j = 0; j < M; ++j){
            if((mask >> j) & 1){
                int cost = abs(emptyCells[i].first - extraCells[j].first) +
                           abs(emptyCells[i].second - extraCells[j].second) +
                           solve(i + 1, mask - (1 << j), emptyCells, extraCells, memo);
                res = min(res, cost);
            }
        }

        memo[mask] = res;
        return res;
    }

public:
    int minimumMoves(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<pair<int, int>> emptyCells;
        vector<pair<int, int>> extraCells;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0){
                    emptyCells.push_back({row, col});
                }else if(grid[row][col] >= 2){
                    extraCells.resize(extraCells.size() + grid[row][col] - 1, {row, col});
                }
            }
        }
        
        const int M = emptyCells.size();
        const int FULL_MASK = (1 << M) - 1;
        vector<int> memo(FULL_MASK + 1, INF);
        return solve(0, FULL_MASK, emptyCells, extraCells, memo);
    }
};