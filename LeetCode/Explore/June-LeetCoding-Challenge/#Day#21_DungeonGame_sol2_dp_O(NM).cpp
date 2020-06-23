class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int N = dungeon.size();
        const int M = dungeon[0].size();
        
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, 1));
        // dp[i][j] - min health to go from (i, j) to (N - 1, M - 1)
        
        dp[N - 1][M - 1] = max(1, -dungeon[N - 1][M - 1] + 1);
        
        for(int i = N - 2; i >= 0; --i){
            dp[i][M - 1] = max(1, dp[i + 1][M - 1] - dungeon[i][M - 1]);
        }
        
        for(int j = M - 2; j >= 0; --j){
            dp[N - 1][j] = max(1, dp[N - 1][j + 1] - dungeon[N - 1][j]);
        }
        
        for(int i = N - 2; i >= 0; --i){
            for(int j = M - 2; j >= 0; --j){
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};