class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        static const int INF = 1e9;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0){
                    int upDist = (row - 1 >= 0 ? grid[row - 1][col] : INF);
                    int leftDist = (col - 1 >= 0 ? grid[row][col - 1] : INF);
                    grid[row][col] = min(upDist + 1, leftDist + 1);
                }
            }
        }

        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = COLS - 1; col >= 0; --col){
                if(grid[row][col] != 1){
                    int downDist = (row + 1 < ROWS ? grid[row + 1][col] : INF);
                    int rightDist = (col + 1 < COLS ? grid[row][col + 1] : INF);
                    grid[row][col] = min({grid[row][col], downDist + 1, rightDist + 1});
                }
            }
        }

        int res = -1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] >= 2 && grid[row][col] < INF){
                    res = max(res, grid[row][col] - 1);
                }
                if(grid[row][col] >= 2){
                    grid[row][col] = 0;
                }
            }
        }
        
        return res;
    }
};