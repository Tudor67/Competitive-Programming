class Solution {
public:
    int climbStairs(int N) {
        // dp[i]: number of distinct ways to reach the top of a staircase with height i
        vector<int> dp(N + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= N; ++i){
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[N];
    }
};