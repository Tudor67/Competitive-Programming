class Solution {
public:
    long long coloredCells(int n) {
        vector<long long> dp(n + 1);
        
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + i + i + (i - 2) + (i - 2);
        }
        
        return dp[n];
    }
};