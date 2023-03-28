class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int D = days.size();
        const vector<int> CONSECUTIVE_DAYS = {1, 7, 30};
        const int INF = 1e9;

        // dp[i]: min cost to travel days[i .. D - 1]
        vector<int> dp(D + 1, INF);
        dp[D] = 0;

        for(int i = D - 1; i >= 0; --i){
            for(int costIndex = 0; costIndex < (int)costs.size(); ++costIndex){
                int j = lower_bound(days.begin() + i, days.end(), days[i] + CONSECUTIVE_DAYS[costIndex]) - days.begin();
                dp[i] = min(dp[i], costs[costIndex] + dp[j]);
            }
        }

        return dp[0];
    }
};