class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MODULO = 1e9 + 7;
        
        vector<vector<int>> dp(2, vector<int>(target + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            fill(dp[i % 2].begin(), dp[i % 2].end(), 0);
            for(int sum = i; sum <= target; ++sum){
                for(int j = 1; j <= min(k, sum); ++j){
                    dp[i % 2][sum] += dp[(i - 1) % 2][sum - j];
                    dp[i % 2][sum] %= MODULO;
                }
            }
        }
        
        return dp[n % 2][target];
    }
};