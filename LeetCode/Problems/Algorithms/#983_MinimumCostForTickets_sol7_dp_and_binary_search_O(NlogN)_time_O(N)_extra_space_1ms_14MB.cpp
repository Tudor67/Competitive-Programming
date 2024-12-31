class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int N = days.size();
        const int INF = 1e9;
        const vector<int> PASS_DURATIONS = {1, 7, 30};

        // dp[i]: min cost for days[0 .. i]
        vector<int> dp(N, INF);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < (int)PASS_DURATIONS.size(); ++j){
                int k = lower_bound(days.begin(), days.begin() + i, days[i] - PASS_DURATIONS[j] + 1)
                        - days.begin();

                if(k == 0){
                    dp[i] = min(dp[i], costs[j]);
                }else{
                    dp[i] = min(dp[i], dp[k - 1] + costs[j]);
                }
            }
        }

        return dp[N - 1];
    }
};