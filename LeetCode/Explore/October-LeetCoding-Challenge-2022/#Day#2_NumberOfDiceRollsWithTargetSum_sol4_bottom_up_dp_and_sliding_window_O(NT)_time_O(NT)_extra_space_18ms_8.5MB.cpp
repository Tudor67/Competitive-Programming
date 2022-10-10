class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MODULO = 1e9 + 7;
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            int wSum = 0;
            for(int sum = 1; sum <= target; ++sum){
                wSum += dp[i - 1][sum - 1];
                wSum %= MODULO;
                if(sum - 1 >= k){
                    wSum -= dp[i - 1][sum - 1 - k];
                    wSum += MODULO;
                    wSum %= MODULO;
                }
                if(sum >= i){
                    // wSum = dp[i - 1][sum - k] + dp[i - 1][sum - (k - 1)] + ... + dp[i - 1][sum - 1]
                    dp[i][sum] = wSum;
                }
            }
        }
        
        return dp[n][target];
    }
};