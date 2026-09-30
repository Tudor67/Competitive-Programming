class Solution {
public:
    int stoneGameV(vector<int>& stoneValues) {
        const int N = stoneValues.size();

        // dp[i][j]: max score we can obtain from stoneValues[i .. j]
        vector<vector<int>> dp(N, vector<int>(N));

        for(int len = 2; len <= N; ++len){
            for(int i = 0, j = i + len - 1; j < N; ++i, ++j){
                int leftScore = 0;
                int rightScore = accumulate(stoneValues.begin() + i, stoneValues.begin() + j + 1, 0);
                for(int k = i; k < j; ++k){
                    leftScore += stoneValues[k];
                    rightScore -= stoneValues[k];

                    if(leftScore <= rightScore){
                        dp[i][j] = max(dp[i][j], dp[i][k] + leftScore);
                    }
                    if(leftScore >= rightScore){
                        dp[i][j] = max(dp[i][j], dp[k + 1][j] + rightScore);
                    }
                }
            }
        }

        return dp[0][N - 1];
    }
};