class Solution {
public:
    int climbStairs(int N) {
        // At ith iteration:
        //    dp[i % 3]: number of distinct ways to reach the top of a staircase with height i
        vector<int> dp(3);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= N; ++i){
            dp[i % 3] = dp[(i - 2) % 3] + dp[(i - 1) % 3];
        }
        return dp[N % 3];
    }
};