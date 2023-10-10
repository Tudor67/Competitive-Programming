class Solution {
public:
    int integerBreak(int N) {
        // dp[s]: max product of k (k >= 2) positive integers with sum s
        vector<int> dp(N + 1);
        for(int s = 2; s <= N; ++s){
            for(int i = 1; i <= s - 1; ++i){
                dp[s] = max(dp[s], max((s - i) * i, dp[s - i] * i));
            }
        }
        return dp[N];
    }
};