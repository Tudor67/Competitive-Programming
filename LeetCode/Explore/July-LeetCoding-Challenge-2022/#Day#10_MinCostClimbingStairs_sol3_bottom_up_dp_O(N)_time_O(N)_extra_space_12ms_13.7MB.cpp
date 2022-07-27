class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = cost.size();
        
        // dp[i]: min cost to reach ith step
        vector<int> dp(N);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < N; ++i){
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        }
        
        return min(dp[N - 2], dp[N - 1]);
    }
};