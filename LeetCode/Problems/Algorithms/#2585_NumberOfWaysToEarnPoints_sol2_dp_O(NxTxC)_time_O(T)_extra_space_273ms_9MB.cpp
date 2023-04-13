class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const int N = types.size();
        const int MODULO = 1e9 + 7;
        
        // At ith iteration:
        //    dp[i % 2][j]: number of ways (% MODULO) we can earn j points
        //                  with questions from types[0 .. i]
        vector<vector<int>> dp(2, vector<int>(target + 1));

        for(int i = 0; i < 2; ++i){
            dp[i % 2][0] = 1;
        }

        int count = types[0][0];
        int marks = types[0][1];
        for(int j = 1; j <= count && j * marks <= target; ++j){
            dp[0][j * marks] = 1;
        }
        
        for(int i = 1; i < N; ++i){
            int count = types[i][0];
            int marks = types[i][1];

            dp[i % 2] = dp[(i - 1) % 2];
            for(int sum = marks; sum <= target; ++sum){
                for(int j = 1; j <= count && sum - j * marks >= 0; ++j){
                    dp[i % 2][sum] += dp[(i - 1) % 2][sum - j * marks];
                    dp[i % 2][sum] %= MODULO;
                }
            }
        }
        
        return dp[(N - 1) % 2][target];
    }
};