class Solution {
private:
    int computeMaxScore(int index, int m, vector<int>& suffSum, vector<vector<int>>& memo){
        const int N = suffSum.size();

        if(index >= N){
            return 0;
        }

        if(memo[index][m] != -1){
            return memo[index][m];
        }

        int maxScore = 0;
        for(int i = index; i <= min(index + 2 * m - 1, N - 1); ++i){
            int score = suffSum[index] - computeMaxScore(i + 1, max(min(i - index + 1, N), m), suffSum, memo);
            maxScore = max(maxScore, score);
        }

        memo[index][m] = maxScore;
        return memo[index][m];
    }

public:
    int stoneGameII(vector<int>& piles) {
        const int N = piles.size();

        vector<int> suffSum(N);
        suffSum[N - 1] = piles[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffSum[i] = piles[i] + suffSum[i + 1];
        }

        vector<vector<int>> memo(N + 1, vector<int>(N + 1, -1));
        return computeMaxScore(0, 1, suffSum, memo);
    }
};