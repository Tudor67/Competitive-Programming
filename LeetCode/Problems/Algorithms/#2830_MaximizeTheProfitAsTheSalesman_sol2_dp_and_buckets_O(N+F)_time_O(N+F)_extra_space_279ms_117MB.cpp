class Solution {
public:
    int maximizeTheProfit(int N, vector<vector<int>>& offers) {
        const int F = offers.size();

        vector<vector<int>> startToOffersIndices(N + 1);
        for(int i = 0; i < F; ++i){
            startToOffersIndices[offers[i][0]].push_back(i);
        }

        // dp[startHouse]: max gold we can earn from startHouse, startHouse + 1, ..., N - 1
        vector<int> dp(N + 1);
        for(int startHouse = N - 1; startHouse >= 0; --startHouse){
            dp[startHouse] = dp[startHouse + 1];
            for(int i: startToOffersIndices[startHouse]){
                int iEnd = offers[i][1];
                int iGold = offers[i][2];
                dp[startHouse] = max(dp[startHouse], iGold + dp[iEnd + 1]);
            }
        }

        return dp[0];
    }
};