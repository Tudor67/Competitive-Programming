class Solution {
public:
    int countBinaryStrings(int n, int k) {
        // dp[i]: number of binary strings of length i
        //        with at most k consecutive ones
        vector<int> dp(n + 1);
        for(int i = 0; i <= k; ++i){
            dp[i] = (1 << i);
        }
        for(int i = k + 1; i <= n; ++i){
            for(int j = i - 1; j >= i - k - 1; --j){
                dp[i] += dp[j];
            }
        }
        return dp[n];
    }
};