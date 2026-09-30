class Solution {
private:
    int computeMaxScore(int l, int r, vector<int>& scores, vector<vector<int>>& memo){
        if(l >= r){
            return 0;
        }

        if(memo[l][r] != -1){
            return memo[l][r];
        }

        int maxScore = 0;
        int leftScore = 0;
        int rightScore = accumulate(scores.begin() + l, scores.begin() + r + 1, 0);

        for(int i = l; i <= r - 1; ++i){
            leftScore += scores[i];
            rightScore -= scores[i];
            if(leftScore <= rightScore){
                maxScore = max(maxScore, leftScore + computeMaxScore(l, i, scores, memo));
            }
            if(leftScore >= rightScore){
                maxScore = max(maxScore, rightScore + computeMaxScore(i + 1, r, scores, memo));
            }
        }

        memo[l][r] = maxScore;
        return maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        const int N = stoneValue.size();
        vector<vector<int>> memo(N, vector<int>(N, -1));
        return computeMaxScore(0, N - 1, stoneValue, memo);
    }
};