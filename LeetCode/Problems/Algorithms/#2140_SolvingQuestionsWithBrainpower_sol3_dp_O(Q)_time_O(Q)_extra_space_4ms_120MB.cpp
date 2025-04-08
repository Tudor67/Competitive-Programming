class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int Q = questions.size();

        // dp[i]: max profit from questions[i .. Q - 1]
        vector<long long> dp(Q + 1);
        for(int i = Q - 1; i >= 0; --i){
            int points = questions[i][0];
            int brainpower = questions[i][1];
            long long takeProfit = points + dp[min(i + brainpower + 1, Q)];
            long long skipProfit = dp[i + 1];
            dp[i] = max(takeProfit, skipProfit);
        }

        return dp[0];
    }
};