class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;
        
        int res = 0;
        vector<vector<int>> dp(ROWS, vector<int>(COLS));
        for(int col = 1; col < COLS; ++col){
            for(int row = 0; row < ROWS; ++row){
                dp[row][col] = -INF;
                for(int rowDir: {-1, 0, 1}){
                    int prevRow = row + rowDir;
                    if(0 <= prevRow && prevRow < ROWS && grid[prevRow][col - 1] < grid[row][col]){
                        dp[row][col] = max(dp[row][col], dp[prevRow][col - 1] + 1);
                    }
                }
                res = max(res, dp[row][col]);
            }
        }
        
        return res;
    }
};