class Solution {
public:
    int minCost(int N, vector<int>& cuts) {
        vector<int> sortedCuts = cuts;

        sortedCuts.push_back(0);
        sortedCuts.push_back(N);
        sort(sortedCuts.begin(), sortedCuts.end());

        const int C = sortedCuts.size();
        const int INF = 1e9;

        // dp[l][r]: min cost for sortedCuts[l .. r]
        vector<vector<int>> dp(C, vector<int>(C));
        for(int r = 2; r < C; ++r){
            for(int l = r - 2; l >= 0; --l){
                dp[l][r] = INF;
                for(int i = l + 1; i + 1 <= r; ++i){
                    dp[l][r] = min(dp[l][r], sortedCuts[r] - sortedCuts[l] + dp[l][i] + dp[i][r]);
                }
            }
        }

        return dp[0][C - 1];
    }
};