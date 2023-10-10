class Solution {
public:
    int integerBreak(int N) {
        if(N <= 3){
            return N - 1;
        }

        // dp[s]: max product of k (k >= 2) positive integers with sum s
        vector<int> dp(N + 1, 1);
        for(int i = 1; i <= N; ++i){
            for(int s = i; s <= N; ++s){
                dp[s] = max(dp[s], dp[s - i] * i);
            }
        }

        return dp[N];
    }
};