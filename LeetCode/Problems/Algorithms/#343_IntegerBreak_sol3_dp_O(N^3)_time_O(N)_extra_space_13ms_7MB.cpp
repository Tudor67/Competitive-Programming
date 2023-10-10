class Solution {
public:
    int integerBreak(int N) {
        // At kth iteration:
        //    dp[k % 2][s]: max product of k positive integers with sum s
        vector<vector<int>> dp(2, vector<int>(N + 1));
        for(int i = 0; i <= N; ++i){
            dp[1][i] = i;
        }

        int res = 0;
        for(int k = 2; k <= N; ++k){
            fill(dp[k % 2].begin(), dp[k % 2].end(), 0);
            for(int i = 1; i <= N; ++i){
                for(int s = i; s <= N; ++s){
                    dp[k % 2][s] = max(dp[k % 2][s], dp[(k - 1) % 2][s - i] * i);
                }
            }
            res = max(res, dp[k % 2][N]);
        }

        return res;
    }
};