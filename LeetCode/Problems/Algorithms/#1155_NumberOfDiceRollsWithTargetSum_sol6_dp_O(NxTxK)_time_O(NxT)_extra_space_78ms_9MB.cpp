class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MODULO = 1e9 + 7;

        // dp[i][target]: number of ways to roll the dice i times
        //                such that the sum of numbers equals target
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int sum = 1; sum <= target; ++sum){
                for(int lastVal = 1; lastVal <= min(k, sum); ++lastVal){
                    dp[i][sum] += dp[i - 1][sum - lastVal];
                    dp[i][sum] %= MODULO;
                }
            }
        }

        return dp[n][target];
    }
};