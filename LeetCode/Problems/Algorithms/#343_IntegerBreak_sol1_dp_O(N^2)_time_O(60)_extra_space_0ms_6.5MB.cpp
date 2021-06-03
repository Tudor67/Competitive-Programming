class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for(int i = 3; i <= n; ++i){
            for(int j = 1; j <= i - 1; ++j){
                dp[i] = max({j * (i - j), dp[j] * (i - j), dp[i]});
            }
        }
        return dp[n];
    }
};