class Solution {
public:
    int numTrees(int n) {
        // -> dp[i] represents the number of structurally unique BSTs with exactly i nodes;
        // -> it can be computed by fixing all possible roots (in the range 1 .. i) and
        //    counting the number of unique BSTs in the left (< root) and right (> root) subtrees;
        // -> dp[i] = dp[0] * dp[i - 1] + dp[1] * dp[i - 2] + ... + dp[i - 1] * dp[0].
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= i - 1; ++j){
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};