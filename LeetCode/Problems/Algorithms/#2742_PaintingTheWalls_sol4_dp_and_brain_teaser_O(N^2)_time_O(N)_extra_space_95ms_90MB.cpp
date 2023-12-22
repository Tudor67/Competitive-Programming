class Solution {
public:
    int paintWalls(vector<int>& costs, vector<int>& times) {
        const int N = costs.size();
        const int INF = 1e9;

        // dp[w]: min cost to paint at least w walls using both paid and free painters
        // main idea of the knapsack dp:
        //      with costs[i] units of money we can paint (1 + times[i]) walls
        //      the paid painter paints 1 wall (the ith wall)
        //      the free painter paints other times[i] walls (when the paid painter works at the ith wall)
        vector<int> dp(N + 1, INF);
        dp[0] = 0;
        for(int i = 0; i < N; ++i){
            for(int w = N; w >= 1; --w){
                dp[w] = min(dp[w], dp[max(0, w - times[i] - 1)] + costs[i]);
            }
        }

        return dp[N];
    }
};