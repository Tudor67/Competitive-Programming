class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        const int ROWS = a.size();
        const int COLS = a[0].size();
        
        // dp[row][col]: the number of possible unique paths from (0, 0) to (row, col)
        vector<vector<int>> dp(ROWS, vector<int>(COLS));
        
        for(int col = 0; col < COLS; ++col){
            if(a[0][col] == 0){
                dp[0][col] = 1;
            }else{
                break;
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            if(a[row][0] == 0){
                dp[row][0] = 1;
            }else{
                break;
            }
        }
        
        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                if(a[row][col] == 0){
                    if(dp[row - 1][col] <= INT_MAX - dp[row][col - 1]){
                        dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
                    }
                }
            }
        }
        
        return dp[ROWS - 1][COLS - 1];
    }
};