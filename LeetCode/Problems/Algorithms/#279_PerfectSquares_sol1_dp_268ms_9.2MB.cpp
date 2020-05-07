class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        
        dp[0] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i / j; ++j){
                dp[i] = min(1 + dp[i - j * j], dp[i]);
            }
        }
        
        return dp[n];
    }
};