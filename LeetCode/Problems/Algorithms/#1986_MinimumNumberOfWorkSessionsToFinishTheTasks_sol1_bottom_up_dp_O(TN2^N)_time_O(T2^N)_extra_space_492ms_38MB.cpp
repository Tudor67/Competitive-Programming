class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        const int N = tasks.size();
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e8;
        
        // dp[mask][remTime]: min sessions to solve tasks from mask with remTime remaining time
        vector<vector<int>> dp(FULL_MASK + 1, vector<int>(sessionTime + 1, INF));
        dp[0][sessionTime] = 1;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            for(int bit = 0; bit < N; ++bit){
                if(!((mask >> bit) & 1)){
                    for(int remainingTime = 0; remainingTime <= sessionTime; ++remainingTime){
                        if(tasks[bit] <= remainingTime){
                            int nextMask = mask | (1 << bit);
                            int nextRemainingTime = remainingTime - tasks[bit];
                            dp[nextMask][nextRemainingTime] = min(dp[nextMask][nextRemainingTime], dp[mask][remainingTime]);
                        }else{
                            int nextMask = mask | (1 << bit);
                            int nextRemainingTime = sessionTime - tasks[bit];
                            dp[nextMask][nextRemainingTime] = min(dp[nextMask][nextRemainingTime], 1 + dp[mask][remainingTime]);
                        }
                    }
                }
            }
        }
        
        return *min_element(dp[FULL_MASK].begin(), dp[FULL_MASK].end());
    }
};