class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        const int N = cost.size();
        const int MAX_TIME = *max_element(time.begin(), time.end());
        const int TIME_LIMIT = max(N, MAX_TIME);
        const int INF = 1e9 + 5;

        // dp[w][t]: min cost to paint w walls in t units of time
        //           when the work is done by the paid painter (without the help of the free painter)
        vector<vector<int>> dp(N + 1, vector<int>(TIME_LIMIT + 1, INF));
        dp[0][0] = 0;
        for(int i = 0; i < N; ++i){
            for(int w = i + 1; w >= 1; --w){
                for(int t = TIME_LIMIT; t >= time[i]; --t){
                    dp[w][t] = min(dp[w][t], dp[w - 1][t - time[i]] + cost[i]);
                }
            }
        }

        int res = INF;
        for(int w = 1; w <= N; ++w){
            for(int t = N - w; t <= TIME_LIMIT; ++t){
                // the paid painter paints w walls in t units of time (and min cost = dp[w][t])
                // the free painter paints (N - w) walls in (N - w) units of time (and min cost = 0)
                // time of free painter (N - w) <= time of paid painter (t)
                res = min(res, dp[w][t]);
            }
        }

        return res;
    }
};