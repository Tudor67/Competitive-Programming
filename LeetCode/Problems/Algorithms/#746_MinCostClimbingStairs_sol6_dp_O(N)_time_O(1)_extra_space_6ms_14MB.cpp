class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = cost.size();

        // At (N - i)th iteration:
        //    dp[i % 2]: min cost to reach the top of the floor
        //               if we start at the ith staircase
        vector<int> dp(2);
        for(int i = N - 1; i >= 0; --i){
            dp[i % 2] = cost[i] + min(dp[(i + 1) % 2], dp[(i + 2) % 2]);
        }

        return min(dp[0], dp[1]);
    }
};