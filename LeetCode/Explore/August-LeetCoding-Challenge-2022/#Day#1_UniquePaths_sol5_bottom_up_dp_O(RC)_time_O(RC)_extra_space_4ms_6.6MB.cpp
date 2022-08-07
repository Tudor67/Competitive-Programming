class Solution {
public:
    int uniquePaths(int m, int n) {
        const int ROWS = m;
        const int COLS = n;
        
        vector<vector<int>> dp(ROWS, vector<int>(COLS));
        for(int col = 0; col < COLS; ++col){
            dp[0][col] = 1;
        }
        
        for(int row = 1; row < ROWS; ++row){
            dp[row][0] = 1;
        }
        
        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }
        
        return dp[ROWS - 1][COLS - 1];
    }
};