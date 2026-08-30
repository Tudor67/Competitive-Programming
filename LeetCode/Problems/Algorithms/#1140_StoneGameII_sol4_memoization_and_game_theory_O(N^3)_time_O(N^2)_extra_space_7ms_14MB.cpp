class Solution {
private:
    int computeMaxScore(int startIndex, int m, vector<int>& suffSum, vector<vector<int>>& memo){
        const int N = suffSum.size();
        
        if(startIndex >= N){
            return 0;
        }

        if(memo[startIndex][m] != -1){
            return memo[startIndex][m];
        }

        int maxScore = 0;
        for(int x = 1; x <= 2 * m && startIndex + x - 1 < N; ++x){
            int currScore = suffSum[startIndex] -
                            computeMaxScore(startIndex + x, max(m, x), suffSum, memo);
            maxScore = max(maxScore, currScore);
        }

        memo[startIndex][m] = maxScore;
        return memo[startIndex][m];
    }

public:
    int stoneGameII(vector<int>& piles) {
        const int N = piles.size();

        vector<int> suffSum(N);
        suffSum[N - 1] = piles[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffSum[i] = piles[i] + suffSum[i + 1];
        }

        vector<vector<int>> memo(N, vector<int>(N + 1, -1));
        return computeMaxScore(0, 1, suffSum, memo);
    }
};