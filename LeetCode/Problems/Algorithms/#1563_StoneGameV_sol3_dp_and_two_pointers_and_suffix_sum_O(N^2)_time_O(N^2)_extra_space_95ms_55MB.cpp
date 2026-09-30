class Solution {
public:
    int stoneGameV(vector<int>& stoneValues) {
        const int N = stoneValues.size();

        // suffSum[i]: sum(stoneValues[i .. N - 1])
        vector<int> suffSum(N + 1);
        for(int i = N - 1; i >= 0; --i){
            suffSum[i] = stoneValues[i] + suffSum[i + 1];
        }

        auto getRangeSum = [&suffSum](int l, int r) -> int {
            return (suffSum[l] - suffSum[r + 1]);
        };

        // dp[i][j]: max score we can obtain from stoneValues[i .. j]
        vector<vector<int>> dp(N, vector<int>(N));

        // leftBestScore[i][j]: max(dp[i][k] + sum(stoneValues[i .. k])) for i <= k <= j
        // rightBestScore[i][j]: max(dp[k][j] + sum(stoneValues[k .. j])) for i <= k <= j
        vector<vector<int>> leftBestScore(N, vector<int>(N));
        vector<vector<int>> rightBestScore(N, vector<int>(N));

        for(int i = 0; i < N; ++i){
            leftBestScore[i][i] = stoneValues[i];
            rightBestScore[i][i] = stoneValues[i];
        }

        for(int len = 2; len <= N; ++len){
            int k = 0;
            for(int i = 0, j = i + len - 1; j < N; ++i, ++j){
                k = max(k, i);
                while(k < j && getRangeSum(i, k) <= getRangeSum(k + 1, j)){
                    ++k;
                }

                for(int splitIdx = max(i, k - 1); splitIdx <= min(j - 1, k); ++splitIdx){
                    int leftScore = getRangeSum(i, splitIdx);
                    int rightScore = getRangeSum(splitIdx + 1, j);
                    if(leftScore <= rightScore){
                        dp[i][j] = max(dp[i][j], leftBestScore[i][splitIdx]);
                    }
                    if(leftScore >= rightScore){
                        dp[i][j] = max(dp[i][j], rightBestScore[splitIdx + 1][j]);
                    }
                }

                leftBestScore[i][j] = max(leftBestScore[i][j - 1], dp[i][j] + getRangeSum(i, j));
                rightBestScore[i][j] = max(rightBestScore[i + 1][j], dp[i][j] + getRangeSum(i, j));
            }
        }

        return dp[0][N - 1];
    }
};