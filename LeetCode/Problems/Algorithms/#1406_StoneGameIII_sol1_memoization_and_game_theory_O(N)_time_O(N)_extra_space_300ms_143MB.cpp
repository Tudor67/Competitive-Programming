class Solution {
private:
    const int INF = 1e9;

    int computeMaxScore(int startIndex, vector<int>& suffSum, vector<int>& memo){
        const int N = suffSum.size();
        
        if(startIndex >= N){
            return 0;
        }

        if(memo[startIndex] != INF){
            return memo[startIndex];
        }

        int maxScore = -INF;
        for(int i = startIndex; i <= min(startIndex + 2, N - 1); ++i){
            int score = suffSum[startIndex] - computeMaxScore(i + 1, suffSum, memo);
            maxScore = max(maxScore, score);
        }

        memo[startIndex] = maxScore;
        return memo[startIndex];
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int N = stoneValue.size();
        const int TOTAL_SUM = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        vector<int> suffSum(N);
        suffSum[N - 1] = stoneValue[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffSum[i] = stoneValue[i] + suffSum[i + 1];
        }

        vector<int> memo(N, INF);
        int alice = computeMaxScore(0, suffSum, memo);
        int bob = TOTAL_SUM - alice;

        if(alice > bob){
            return "Alice";
        }else if(bob > alice){
            return "Bob";
        }
        return "Tie";
    }
};