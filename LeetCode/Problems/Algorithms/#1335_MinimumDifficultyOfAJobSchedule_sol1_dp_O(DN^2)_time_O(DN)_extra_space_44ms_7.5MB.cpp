class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int N = jobDifficulty.size();
        
        if(N < d){
            return -1;
        }
        
        // dp[k][i]: min difficulty to schedule jobs[0 .. i] in k days
        const int INF = 1e8;
        vector<vector<int>> dp(d + 1, vector<int>(N, INF));
        dp[1][0] = jobDifficulty[0];
        for(int i = 1; i < N; ++i){
            dp[1][i] = max(dp[1][i - 1], jobDifficulty[i]);
        }
        
        for(int k = 2; k <= d; ++k){
            for(int i = 0; i < N; ++i){
                int maxDifficulty = jobDifficulty[i];
                for(int j = i; j >= 1; --j){
                    maxDifficulty = max(maxDifficulty, jobDifficulty[j]);
                    dp[k][i] = min(dp[k][i], dp[k - 1][j - 1] + maxDifficulty);
                }
            }
        }
        
        return dp[d][N - 1];
    }
};