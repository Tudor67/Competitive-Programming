class Solution {
private:
    const int INF = 1e9;

    int getVal(vector<vector<int>>& grid, int row, int col){
        if(0 <= row && row < (int)grid.size() && 0 <= col && col < (int)grid[0].size()){
            return grid[row][col];
        }
        return 0;
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        const int N = fruits.size();

        int res = 0;

        // collect from (0, 0)
        for(int i = 0; i < N; ++i){
            res += fruits[i][i];
            fruits[i][i] = 0;
        }

        // collect from (0, N - 1)
        vector<vector<int>> dp(N, vector<int>(N, -INF));
        dp[0][N - 1] = fruits[0][N - 1];
        for(int row = 1; row < N; ++row){
            for(int col = row + 1; col < N; ++col){
                dp[row][col] = fruits[row][col] + max({getVal(dp, row - 1, col - 1),
                                                       getVal(dp, row - 1, col),
                                                       getVal(dp, row - 1, col + 1)});
            }
        }
        res += dp[N - 2][N - 1];

        // collect from (N - 1, 0)
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                dp[row][col] = -INF;
            }
        }

        dp[N - 1][0] = fruits[N - 1][0];
        for(int col = 1; col < N; ++col){
            for(int row = col + 1; row < N; ++row){
                dp[row][col] = fruits[row][col] + max({getVal(dp, row + 1, col - 1),
                                                       getVal(dp, row, col - 1),
                                                       getVal(dp, row - 1, col - 1)});
            }
        }
        res += dp[N - 1][N - 2];

        return res;
    }
};