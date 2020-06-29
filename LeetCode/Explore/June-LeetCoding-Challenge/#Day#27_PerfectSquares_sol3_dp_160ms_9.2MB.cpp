class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j * j <= i; ++j){
                if(dp[i] == 0 || dp[i - j * j] + 1 < dp[i]){
                    dp[i] = dp[i - j * j] + 1;
                }
            }
        }
        return dp[n];
    }
};