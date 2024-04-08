class Solution {
public:
    int distributeCandies(int n, int limit) {
        limit = min(limit, n);

        // dp[len][s]: number of sequences of length len and sum s
        //             when we use values from the range [0 .. limit]
        vector<vector<int>> dp(4, vector<int>(n + 1));
        for(int sum = 0; sum <= limit; ++sum){
            dp[1][sum] = 1;
        }

        for(int len = 2; len <= 3; ++len){
            int wSum = 0;
            for(int sum = 0; sum <= n; ++sum){
                wSum += dp[len - 1][sum];
                if(sum >= limit + 1){
                    wSum -= dp[len - 1][sum - (limit + 1)];
                }
                dp[len][sum] = wSum;
            }
        }

        return dp[3][n];
    }
};