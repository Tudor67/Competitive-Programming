class Solution {
private:
    int abs(int x){
        return max(x, -x);
    }

public:
    int minimumMoves(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

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
        vector<int> p(M);
        iota(p.begin(), p.end(), 0);
        int minCost = INF;

        do{
            int cost = 0;
            for(int i = 0; i < M; ++i){
                cost += (abs(emptyCells[p[i]].first - extraCells[i].first) +
                         abs(emptyCells[p[i]].second - extraCells[i].second));
            }
            minCost = min(minCost, cost);
        }while(next_permutation(p.begin(), p.end()));

        return minCost;
    }
};