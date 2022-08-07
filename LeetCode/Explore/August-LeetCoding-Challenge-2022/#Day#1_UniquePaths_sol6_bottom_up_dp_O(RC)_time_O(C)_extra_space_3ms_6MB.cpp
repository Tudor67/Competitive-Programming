class Solution {
public:
    int uniquePaths(int m, int n) {
        const int ROWS = m;
        const int COLS = n;
        
        vector<vector<int>> dp(2, vector<int>(COLS));
        for(int col = 0; col < COLS; ++col){
            dp[0][col] = 1;
        }
        
        for(int row = 1; row < ROWS; ++row){
            dp[row % 2][0] = 1;
            for(int col = 1; col < COLS; ++col){
                dp[row % 2][col] = dp[(row - 1) % 2][col] + dp[row % 2][col - 1];
            }
        }
        
        return dp[(ROWS - 1) % 2][COLS - 1];
    }
};