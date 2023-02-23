class Solution {
public:
    int maximizeWin(vector<int>& p, int k) {
        const int N = p.size();
        
        // dp[x][j]: max prizes we can win when we choose x segments (s.t. segment length <= k)
        //           from vector p[0 .. j]
        vector<vector<int>> dp(3, vector<int>(N));

        for(int x = 1; x <= 2; ++x){
            int i = 0;
            for(int j = 0; j < N; ++j){
                while(p[j] - p[i] > k){
                    i += 1;
                }

                int lastSegmentPrizes = j - i + 1;
                dp[x][j] = lastSegmentPrizes;
                if(j >= lastSegmentPrizes){
                    dp[x][j] += dp[x - 1][j - lastSegmentPrizes];
                }

                if(j >= 1){
                    dp[x][j] = max(dp[x][j], dp[x][j - 1]);
                }
            }
        }

        return dp[2][N - 1];
    }
};