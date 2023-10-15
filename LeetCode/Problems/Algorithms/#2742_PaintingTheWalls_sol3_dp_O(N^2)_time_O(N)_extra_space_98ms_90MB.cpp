class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        const int N = cost.size();
        const int INF = 1e9 + 5;

        // Main idea:
        //   (a) the paid painter paints the ith wall in time[i] units of time;
        //       the paid painter paints 1 wall in time[i] units of time and takes cost[i] units of money;
        //   (b) the free painter paints time[i] walls in time[i] units of time and takes 0 units of money;
        //   (c) for time[i] units of time the paid painter and free painter paint (1 + time[i]) walls and
        //                                                                   take (cost[i] + 0) units of money;
        //   (d) we should compute the minimum cost to paint N walls;
        //   (e) this is a standard dp problem: the knapsack problem;
        //   (f) dp[w]: min cost to paint at least w walls when we use paid painter and free painter;
        vector<int> dp(N + 1, INF);
        dp[0] = 0;
        for(int i = 0; i < N; ++i){
            for(int w = N; w >= 1; --w){
                dp[w] = min(dp[w], dp[max(0, w - time[i] - 1)] + cost[i]);
            }
        }

        return dp[N];
    }
};