class Solution {
public:
    int integerBreak(int N) {
        // dp[k][s]: max product of k positive integers with sum s
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        for(int i = 0; i <= N; ++i){
            dp[1][i] = i;
        }

        int res = 0;
        for(int k = 2; k <= N; ++k){
            for(int i = 1; i <= N; ++i){
                for(int s = i; s <= N; ++s){
                    dp[k][s] = max(dp[k][s], dp[k - 1][s - i] * i);
                }
            }
            res = max(res, dp[k][N]);
        }

        return res;
    }
};