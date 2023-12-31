class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MODULO = 1e9 + 7;

        // dp[i][target]: number of ways to roll the dice i times
        //                such that the sum of numbers equals target
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            int wSum = 0;
            for(int sum = 1; sum <= target; ++sum){
                wSum = (wSum + dp[i - 1][sum - 1]) % MODULO;
                if(sum >= k + 1){
                    wSum = (wSum + MODULO - dp[i - 1][sum - (k + 1)]) % MODULO;
                }
                dp[i][sum] = wSum;
            }
        }

        return dp[n][target];
    }
};