class Solution {
private:
    long long solve(int i, vector<vector<int>>& questions, vector<long long>& memo){
        if(i >= (int)questions.size()){
            return 0;
        }
        if(memo[i] >= 0){
            return memo[i];
        }
        long long takeProfit = questions[i][0] + solve(i + questions[i][1] + 1, questions, memo);
        long long skipProfit = solve(i + 1, questions, memo);
        memo[i] = max(takeProfit, skipProfit);
        return memo[i];
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int Q = questions.size();
        vector<long long> memo(Q, -1);
        return solve(0, questions, memo);
    }
};