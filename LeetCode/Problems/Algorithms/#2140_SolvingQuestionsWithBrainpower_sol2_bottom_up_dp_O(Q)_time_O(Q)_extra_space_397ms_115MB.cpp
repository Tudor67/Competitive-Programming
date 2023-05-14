class Solution {
private:
    long long getVal(vector<long long>& dp, int i){
        if(0 <= i && i < (int)dp.size()){
            return dp[i];
        }
        return 0;
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int Q = questions.size();

        // dp[i]: max profit from questions[i .. Q - 1]
        vector<long long> dp(Q);
        for(int i = Q - 1; i >= 0; --i){
            long long takeProfit = questions[i][0] + getVal(dp, i + questions[i][1] + 1);
            long long skipProfit = getVal(dp, i + 1);
            dp[i] = max(takeProfit, skipProfit);
        }

        return dp[0];
    }
};