class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        const int N = piles.size();

        // dp[i][k]: max value of coins we can collect from piles[i .. N - 1]
        //           when we choose at most k coins
        vector<vector<int>> dp(N + 1, vector<int>(k + 1));

        for(int i = N - 1; i >= 0; --i){
            int prefSum = 0;
            for(int k1 = 0; k1 <= min(k, (int)piles[i].size()); ++k1){
                if(k1 >= 1){
                    prefSum += piles[i][k1 - 1];
                }
                for(int k2 = 0; k1 + k2 <= k; ++k2){
                    dp[i][k1 + k2] = max(dp[i][k1 + k2], prefSum + dp[i + 1][k2]);
                }
            }
        }

        return dp[0][k];
    }
};