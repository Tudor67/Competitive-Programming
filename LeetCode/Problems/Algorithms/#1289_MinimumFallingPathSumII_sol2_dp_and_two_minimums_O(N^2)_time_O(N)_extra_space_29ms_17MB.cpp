class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        // At (row)th iteration:
        //    dp[col]: min falling path sum at (row, col)
        vector<int> dp(COLS);
        for(int col = 0; col < COLS; ++col){
            dp[col] = grid[0][col];
        }

        for(int row = 1; row < ROWS; ++row){
            pair<int, int> prevMin1 = {INF, -1};
            pair<int, int> prevMin2 = {INF, -1};
            for(int col = 0; col < COLS; ++col){
                pair<int, int> p = {dp[col], col};
                if(p < prevMin1){
                    prevMin2 = prevMin1;
                    prevMin1 = p;
                }else if(p < prevMin2){
                    prevMin2 = p;
                }
            }

            for(int col = 0; col < COLS; ++col){
                if(prevMin1.second == col){
                    dp[col] = prevMin2.first + grid[row][col];
                }else{
                    dp[col] = prevMin1.first + grid[row][col];
                }
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};