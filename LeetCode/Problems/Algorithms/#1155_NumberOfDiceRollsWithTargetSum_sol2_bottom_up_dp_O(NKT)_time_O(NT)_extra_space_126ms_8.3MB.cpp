class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MODULO = 1e9 + 7;
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int sum = i; sum <= target; ++sum){
                for(int j = 1; j <= min(k, sum); ++j){
                    dp[i][sum] += dp[i - 1][sum - j];
                    dp[i][sum] %= MODULO;
                }
            }
        }
        
        return dp[n][target];
    }
};