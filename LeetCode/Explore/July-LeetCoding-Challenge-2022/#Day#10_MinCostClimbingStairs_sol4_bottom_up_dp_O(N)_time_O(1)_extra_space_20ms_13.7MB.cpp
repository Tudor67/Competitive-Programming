class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = cost.size();
        
        // At ith step:
        //    dp[i % 3]: min cost to reach ith step
        vector<int> dp(3);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < N; ++i){
            dp[i % 3] = min(dp[(i - 2) % 3], dp[(i - 1) % 3]) + cost[i];
        }
        
        return min(dp[(N - 2) % 3], dp[(N - 1) % 3]);
    }
};