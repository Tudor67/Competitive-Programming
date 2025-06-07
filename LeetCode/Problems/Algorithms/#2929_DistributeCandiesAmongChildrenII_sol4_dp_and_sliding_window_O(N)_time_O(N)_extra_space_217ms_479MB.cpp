class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // dp[i][j]: total number of ways to distribute j candies among (i + 1) children
        //           such that no child gets more than limit candies
        vector<vector<long long>> dp(3, vector<long long>(n + 1));

        for(int j = 0; j <= min(limit, n); ++j){
            dp[0][j] = 1;
        }

        for(int i = 1; i <= 2; ++i){
            long long wSum = 0;
            for(int j = 0; j <= n; ++j){
                wSum += dp[i - 1][j];
                if(j >= limit + 1){
                    wSum -= dp[i - 1][j - (limit + 1)];
                }
                dp[i][j] = wSum;
            }
        }

        return dp[2][n];
    }
};