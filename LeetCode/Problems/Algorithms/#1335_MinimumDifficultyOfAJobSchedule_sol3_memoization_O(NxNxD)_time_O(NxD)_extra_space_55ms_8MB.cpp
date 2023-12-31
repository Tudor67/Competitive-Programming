class Solution {
private:
    const int INF = 1e9;

    int solve(int d, int i, int maxDifficulty, vector<int>& jobDifficulty, vector<vector<int>>& memo){
        const int N = jobDifficulty.size();

        if(i == N){
            if(d == 0){
                return 0;
            }else{
                return INF;
            }
        }

        if(d == 0){
            return INF;
        }

        if(memo[d][i] != -1){
            return memo[d][i];
        }

        int minCost = INF;
        for(int j = i; j < N; ++j){
            maxDifficulty = max(maxDifficulty, jobDifficulty[j]);
            int cost = maxDifficulty + solve(d - 1, j + 1, INT_MIN, jobDifficulty, memo);
            minCost = min(minCost, cost);
        }

        memo[d][i] = minCost;
        return minCost;
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int N = jobDifficulty.size();
        
        if(N < d){
            return -1;
        }

        vector<vector<int>> memo(d + 1, vector<int>(N, -1));
        return solve(d, 0, INT_MIN, jobDifficulty, memo);
    }
};