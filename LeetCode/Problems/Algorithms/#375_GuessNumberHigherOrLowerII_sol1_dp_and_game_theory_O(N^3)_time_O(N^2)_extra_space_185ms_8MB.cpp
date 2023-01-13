class Solution {
public:
    int getMoneyAmount(int N) {
        const int INF = 1e9;

        // dp[i][j]: min cost to guess a number in range [i .. j]
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));
        for(int i = 1; i <= N; ++i){
            dp[i][i] = 0;
        }

        for(int len = 2; len <= N; ++len){
            for(int i = 1; i + len - 1 <= N; ++i){
                int j = i + len - 1;
                for(int mid = i; mid <= j; ++mid){
                    int leftDP = (i <= mid - 1 ? dp[i][mid - 1] : 0);
                    int rightDP = (mid + 1 <= j ? dp[mid + 1][j] : 0);
                    dp[i][j] = min(dp[i][j], mid + max(leftDP, rightDP));
                }
            }
        }

        return dp[1][N];
    }
};