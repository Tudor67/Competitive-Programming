class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int ROWS = dungeon.size();
        const int COLS = dungeon[0].size();
        
        // dp[row][col]: min health if the initial position of the knight is (row, col)
        vector<vector<int>> dp(ROWS, vector<int>(COLS));
        dp[ROWS - 1][COLS - 1] = max(1, -dungeon[ROWS - 1][COLS - 1] + 1);
        
        for(int row = ROWS - 2; row >= 0; --row){
            dp[row][COLS - 1] = max(1, -dungeon[row][COLS - 1] + dp[row + 1][COLS - 1]);
        }
        
        for(int col = COLS - 2; col >= 0; --col){
            dp[ROWS - 1][col] = max(1, -dungeon[ROWS - 1][col] + dp[ROWS - 1][col + 1]);
        }
        
        for(int row = ROWS - 2; row >= 0; --row){
            for(int col = COLS - 2; col >= 0; --col){
                dp[row][col] = max(1, -dungeon[row][col] + min(dp[row + 1][col], dp[row][col + 1]));
            }
        }
        
        return dp[0][0];
    }
};