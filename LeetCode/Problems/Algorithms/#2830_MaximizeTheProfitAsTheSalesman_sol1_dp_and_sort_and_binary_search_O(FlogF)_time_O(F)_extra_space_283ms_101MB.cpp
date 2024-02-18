class Solution {
public:
    int maximizeTheProfit(int N, vector<vector<int>>& offers) {
        const int F = offers.size();
        const int INF = 1e9;

        vector<tuple<int, int, int>> sortedOffers(F);
        for(int i = 0; i < F; ++i){
            sortedOffers[i] = {offers[i][0], offers[i][1], offers[i][2]};
        }

        sort(sortedOffers.begin(), sortedOffers.end());

        // dp[i]: max gold we can earn from sortedOffers[i .. F - 1]
        vector<int> dp(F + 1);
        for(int i = F - 1; i >= 0; --i){
            int iEnd = get<1>(sortedOffers[i]);
            int iGold = get<2>(sortedOffers[i]);
            int j = upper_bound(sortedOffers.begin() + i + 1, sortedOffers.end(),
                                tuple<int, int, int>{iEnd, INF, INF}) - sortedOffers.begin();
            dp[i] = max(dp[i + 1], iGold + dp[j]);
        }

        return dp[0];
    }
};